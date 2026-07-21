#include "RVec.h"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#if defined(HAVE_READLINE)
    #include <readline/history.h>
    #include <readline/readline.h>
#endif

namespace {

using VectorStore = std::unordered_map<std::string, RVec>;

std::string trim(const std::string& text)
{
    std::size_t first = 0;
    while(first < text.size() &&
          std::isspace(static_cast<unsigned char>(text[first]))){
        ++first;
    }

    std::size_t last = text.size();
    while(last > first &&
          std::isspace(static_cast<unsigned char>(text[last - 1]))){
        --last;
    }

    return text.substr(first, last - first);
}

void print_help()
{
    std::cout
        << "Commands:\n"
        << "  vector v(x1, x2, ..., xn)    Create or replace a vector in R^n\n"
        << "  a + b + ...                  Add a chain of vectors\n"
        << "  vector v = a + b + ...       Add vectors and store the result\n"
        << "  show <name>                  Display a stored vector\n"
        << "  dimension <name>             Display a vector's dimension\n"
        << "  add <first> <second>         Add two vectors\n"
        << "  list                         Display all stored vectors\n"
        << "  help                         Display this help\n"
        << "  quit                         Exit the REPL\n";
}

bool is_valid_name(const std::string& name)
{
    if(name.empty() ||
       (!std::isalpha(static_cast<unsigned char>(name.front())) &&
        name.front() != '_')){
        return false;
    }

    for(const char character : name){
        if(!std::isalnum(static_cast<unsigned char>(character)) &&
           character != '_'){
            return false;
        }
    }
    return true;
}

double parse_number(const std::string& text)
{
    std::size_t parsed = 0;
    double value = 0.0;
    try {
        value = std::stod(text, &parsed);
    } catch(const std::exception&){
        throw std::invalid_argument("'" + text + "' is not a finite number");
    }

    if(parsed != text.size() || !std::isfinite(value)){
        throw std::invalid_argument("'" + text + "' is not a finite number");
    }
    return value;
}

const RVec& find_vector(const VectorStore& vectors, const std::string& name)
{
    const auto found = vectors.find(name);
    if(found == vectors.end()){
        throw std::invalid_argument("no vector named '" + name + "'");
    }
    return found->second;
}

void print_vector(const RVec& vector)
{
    std::cout << '(';
    for(std::size_t index = 0; index < vector.dimension(); ++index){
        if(index != 0){
            std::cout << ", ";
        }
        std::cout << vector[index];
    }
    std::cout << ')';
}

void require_argument_count(const std::vector<std::string>& arguments,
                            std::size_t expected,
                            const std::string& usage)
{
    if(arguments.size() != expected){
        throw std::invalid_argument("usage: " + usage);
    }
}

RVec evaluate_addition(const std::string& expression,
                       const VectorStore& vectors)
{
    std::size_t position = 0;
    const std::size_t first_plus = expression.find('+');
    const std::string first_name = trim(expression.substr(0, first_plus));
    if(!is_valid_name(first_name)){
        throw std::invalid_argument("expected a vector name before '+'");
    }

    RVec result = find_vector(vectors, first_name);
    if(first_plus == std::string::npos){
        return result;
    }
    position = first_plus + 1;

    while(true){
        const std::size_t plus = expression.find('+', position);
        const std::size_t end = plus == std::string::npos
                                    ? expression.size()
                                    : plus;
        const std::string name = trim(expression.substr(position, end - position));
        if(!is_valid_name(name)){
            throw std::invalid_argument("expected a vector name after '+'");
        }

        result = result + find_vector(vectors, name);
        if(plus == std::string::npos){
            break;
        }
        position = plus + 1;
    }

    return result;
}

void create_vector(const std::string& line, VectorStore& vectors)
{
    const std::string declaration = trim(line.substr(std::string("vector").size()));
    const std::size_t equals = declaration.find('=');
    if(equals != std::string::npos){
        if(declaration.find('=', equals + 1) != std::string::npos){
            throw std::invalid_argument("a vector assignment must contain one '='");
        }

        const std::string name = trim(declaration.substr(0, equals));
        if(!is_valid_name(name)){
            throw std::invalid_argument("'" + name + "' is not a valid vector name");
        }

        const std::string expression = trim(declaration.substr(equals + 1));
        if(expression.empty()){
            throw std::invalid_argument("expected an addition expression after '='");
        }

        vectors.insert_or_assign(name, evaluate_addition(expression, vectors));
        std::cout << name << " = ";
        print_vector(vectors.at(name));
        std::cout << '\n';
        return;
    }

    const std::size_t open_parenthesis = declaration.find('(');
    const std::size_t close_parenthesis = declaration.rfind(')');

    if(open_parenthesis == std::string::npos ||
       close_parenthesis == std::string::npos ||
       close_parenthesis < open_parenthesis ||
       !trim(declaration.substr(close_parenthesis + 1)).empty()){
        throw std::invalid_argument("usage: vector v(x1, x2, ..., xn)");
    }

    const std::string name = trim(declaration.substr(0, open_parenthesis));
    if(!is_valid_name(name)){
        throw std::invalid_argument("'" + name + "' is not a valid vector name");
    }

    const std::string component_text =
        declaration.substr(open_parenthesis + 1,
                           close_parenthesis - open_parenthesis - 1);
    if(trim(component_text).empty()){
        throw std::invalid_argument("a vector must have at least one component");
    }

    std::vector<double> components;
    std::size_t position = 0;
    while(position <= component_text.size()){
        const std::size_t comma = component_text.find(',', position);
        const std::size_t end = comma == std::string::npos
                                    ? component_text.size()
                                    : comma;
        const std::string component =
            trim(component_text.substr(position, end - position));
        if(component.empty()){
            throw std::invalid_argument("vector components cannot be empty");
        }
        components.push_back(parse_number(component));

        if(comma == std::string::npos){
            break;
        }
        position = comma + 1;
    }

    vectors.insert_or_assign(name, RVec(std::move(components)));
    std::cout << name << " = ";
    print_vector(vectors.at(name));
    std::cout << '\n';
}

void run_command(const std::vector<std::string>& arguments, VectorStore& vectors)
{
    const std::string& command = arguments.front();

    if(command == "help"){
        require_argument_count(arguments, 1, "help");
        print_help();
    } else if(command == "show"){
        require_argument_count(arguments, 2, "show <name>");
        print_vector(find_vector(vectors, arguments[1]));
        std::cout << '\n';
    } else if(command == "dimension"){
        require_argument_count(arguments, 2, "dimension <name>");
        std::cout << find_vector(vectors, arguments[1]).dimension() << '\n';
    } else if(command == "add"){
        require_argument_count(arguments, 3, "add <first> <second>");
        const RVec sum = find_vector(vectors, arguments[1]) +
                         find_vector(vectors, arguments[2]);
        print_vector(sum);
        std::cout << '\n';
    } else if(command == "list"){
        require_argument_count(arguments, 1, "list");
        if(vectors.empty()){
            std::cout << "No vectors stored.\n";
            return;
        }

        for(const auto& [name, vector] : vectors){
            std::cout << name << " = ";
            print_vector(vector);
            std::cout << " in R^" << vector.dimension() << '\n';
        }
    } else{
        throw std::invalid_argument("unknown command '" + command +
                                    "'; type 'help'");
    }
}

bool process_line(const std::string& line, VectorStore& vectors)
{
    std::istringstream input(line);
    std::vector<std::string> arguments;
    for(std::string argument; input >> argument;){
        arguments.push_back(std::move(argument));
    }

    if(arguments.empty()){
        return false;
    }
    if(arguments.front() == "quit" || arguments.front() == "exit"){
        if(arguments.size() != 1){
            std::cerr << "Error: usage: quit\n";
            return false;
        }
        return true;
    }

    try {
        if(arguments.front() == "vector"){
            create_vector(line, vectors);
        } else if(line.find('+') != std::string::npos){
            print_vector(evaluate_addition(line, vectors));
            std::cout << '\n';
        } else{
            run_command(arguments, vectors);
        }
    } catch(const std::exception& error){
        std::cerr << "Error: " << error.what() << '\n';
    }
    return false;
}

#if defined(HAVE_READLINE)
std::string history_file_path()
{
    const char* home_directory = std::getenv("HOME");
    if(home_directory == nullptr || home_directory[0] == '\0'){
        return "";
    }
    return std::string(home_directory) + "/.polaris_rvec_history";
}
#endif

} // namespace

int main()
{
    VectorStore vectors;
    std::cout << std::setprecision(15)
              << "Project Polaris RVec REPL (R^n, n >= 1)\n"
              << "Type 'help' for commands or 'quit' to exit.\n";

#if defined(HAVE_READLINE)
    const std::string history_file = history_file_path();
    if(!history_file.empty()){
        (void)read_history(history_file.c_str());
    }

    while(true){
        char* input_line = readline("polaris> ");
        if(input_line == nullptr){
            std::cout << '\n';
            break;
        }

        const std::string line(input_line);
        std::free(input_line);

        if(!trim(line).empty()){
            add_history(line.c_str());
        }
        if(process_line(line, vectors)){
            break;
        }
    }

    if(!history_file.empty()){
        (void)write_history(history_file.c_str());
    }
#else
    std::string line;
    while(std::cout << "polaris> " && std::getline(std::cin, line)){
        if(process_line(line, vectors)){
            break;
        }
    }
#endif

    std::cout << "Goodbye - jole 2026\n";
    return EXIT_SUCCESS;
}
