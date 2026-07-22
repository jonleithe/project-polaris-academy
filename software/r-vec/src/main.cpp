#include "RVec.h"
#include "Parser.h"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
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
        << "  a + b - c ...                Add or subtract vectors\n"
        << "  vector v = a + b - c ...     Evaluate and store the result\n"
        << "  show <name>                  Display a stored vector\n"
        << "  dimension <name>             Display a vector's dimension\n"
        << "  add <first> <second>         Add two vectors\n"
        << "  list                         Display all stored vectors\n"
        << "  help                         Display this help\n"
        << "  quit                         Exit the REPL\n";
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

RVec evaluate_expression(const VectorExpression& expression,
                         const VectorStore& vectors)
{
    RVec result = find_vector(vectors, expression.first);
    for(const ExpressionTerm& term : expression.remaining){
        const RVec& operand = find_vector(vectors, term.name);
        if(term.operation == VectorOperator::add){
            result = result + operand;
        } else{
            result = result - operand;
        }
    }
    return result;
}

bool execute_statement(Statement statement, VectorStore& vectors)
{
    if(std::holds_alternative<EmptyStatement>(statement)){
        return false;
    }
    if(std::holds_alternative<QuitStatement>(statement)){
        return true;
    }
    if(std::holds_alternative<HelpStatement>(statement)){
        print_help();
        return false;
    }
    if(const auto* literal = std::get_if<VectorLiteralStatement>(&statement)){
        vectors.insert_or_assign(literal->name,
                                 RVec(std::move(literal->components)));
        std::cout << literal->name << " = ";
        print_vector(vectors.at(literal->name));
        std::cout << '\n';
        return false;
    }
    if(const auto* assignment =
           std::get_if<VectorAssignmentStatement>(&statement)){
        vectors.insert_or_assign(
            assignment->name,
            evaluate_expression(assignment->expression, vectors));
        std::cout << assignment->name << " = ";
        print_vector(vectors.at(assignment->name));
        std::cout << '\n';
        return false;
    }
    if(const auto* expression = std::get_if<ExpressionStatement>(&statement)){
        print_vector(evaluate_expression(expression->expression, vectors));
        std::cout << '\n';
        return false;
    }
    if(const auto* show = std::get_if<ShowStatement>(&statement)){
        print_vector(find_vector(vectors, show->name));
        std::cout << '\n';
        return false;
    }
    if(const auto* dimension = std::get_if<DimensionStatement>(&statement)){
        std::cout << find_vector(vectors, dimension->name).dimension() << '\n';
        return false;
    }
    if(const auto* add = std::get_if<AddStatement>(&statement)){
        const RVec sum = find_vector(vectors, add->first) +
                         find_vector(vectors, add->second);
        print_vector(sum);
        std::cout << '\n';
        return false;
    }
    if(std::holds_alternative<ListStatement>(statement)){
        if(vectors.empty()){
            std::cout << "No vectors stored.\n";
            return false;
        }

        for(const auto& [name, vector] : vectors){
            std::cout << name << " = ";
            print_vector(vector);
            std::cout << " in R^" << vector.dimension() << '\n';
        }
        return false;
    }

    throw std::logic_error("unhandled parsed statement");
}

bool process_line(const std::string& line, VectorStore& vectors)
{
    try {
        const std::vector<Token> tokens = tokenize(line);
        Parser parser(tokens);
        Statement statement = parser.parse();

        return execute_statement(std::move(statement), vectors);
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
    while(std::cout << "polaris (no history)> " && std::getline(std::cin, line)){
        if(process_line(line, vectors)){
            break;
        }
    }
#endif

    std::cout << "Goodbye - jole 2026\n";
    return EXIT_SUCCESS;
}
