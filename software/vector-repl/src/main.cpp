#include "RVector.h"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#if defined(HAVE_READLINE)
    #include <readline/history.h>
    #include <readline/readline.h>
#endif



namespace {

using VectorStore = std::unordered_map<std::string, RVector>;

void print_help()
{
    std::cout
        << "Commands:\n"
        << "  vector <name> <x> <y> [z]  Create or replace an R2/R3 vector\n"
        << "  magnitude <name>           Calculate a vector's magnitude\n"
        << "  scale <name> <number>       Multiply a vector by a scalar\n"
        << "  add <first> <second>        Add two vectors\n"
        << "  subtract <first> <second>   Subtract the second vector\n"
        << "  dot <first> <second>        Calculate the dot product\n"
        << "  cross <first> <second>      Calculate the R3 cross product\n"
        << "  list                        Show all stored vectors\n"
        << "  help                        Show this help\n"
        << "  quit                        Exit\n";
}



double parse_number(const std::string& text)
{
    std::size_t parsed = 0;
    const double value = std::stod(text, &parsed);
    if(parsed != text.size() || !std::isfinite(value)){
        throw std::invalid_argument("'" + text + "' is not a finite number");
    }
    return value;
}



const RVector& find_vector(const VectorStore& vectors, const std::string& name)
{
    const auto found = vectors.find(name);
    if(found == vectors.end()){
        throw std::invalid_argument("no vector named '" + name + "'");
    }
    return found->second;
}



void require_argument_count(const std::vector<std::string>& arguments,
                            std::size_t expected,
                            const std::string& usage)
{
    if(arguments.size() != expected){
        throw std::invalid_argument("usage: " + usage);
    }
}



void run_command(const std::vector<std::string>& arguments, VectorStore& vectors)
{
    const std::string& command = arguments.front();

    if(command == "help"){
        require_argument_count(arguments, 1, "help");
        print_help();
    } else if(command == "vector"){
        if(arguments.size() != 4 && arguments.size() != 5){
            throw std::invalid_argument("usage: vector <name> <x> <y> [z]");
        }
        std::vector<double> components;
        for(std::size_t index = 2; index < arguments.size(); ++index){
            components.push_back(parse_number(arguments[index]));
        }
        const std::string name = arguments[1];
        vectors.insert_or_assign(name, RVector(std::move(components)));
        std::cout << name << " = " << vectors.at(name) << '\n';
    } else if(command == "magnitude"){
        require_argument_count(arguments, 2, "magnitude <name>");
        std::cout << find_vector(vectors, arguments[1]).magnitude() << '\n';
    } else if(command == "scale"){
        require_argument_count(arguments, 3, "scale <name> <number>");
        std::cout << find_vector(vectors, arguments[1]) * parse_number(arguments[2]) << '\n';
    } else if(command == "add" || command == "subtract" ||
               command == "dot" || command == "cross"){
        require_argument_count(arguments, 3, command + " <first> <second>");
        const RVector& first = find_vector(vectors, arguments[1]);
        const RVector& second = find_vector(vectors, arguments[2]);

        if(command == "add"){
            std::cout << first + second << '\n';
        } else if(command == "subtract"){
            std::cout << first - second << '\n';
        } else if(command == "dot"){
            std::cout << first.dot(second) << '\n';
        } else{
            std::cout << first.cross(second) << '\n';
        }
    } else if(command == "list"){
        require_argument_count(arguments, 1, "list");
        if(vectors.empty()){
            std::cout << "No vectors stored.\n";
        } else{
            for(const auto& [name, vector] : vectors){
                std::cout << name << " = " << vector << '\n';
            }
        }
    } else{
        throw std::invalid_argument("unknown command '" + command + "'; type 'help'");
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
        run_command(arguments, vectors);
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
    }

    return false;
}



#if defined(HAVE_READLINE)
std::string history_file_path()
{
    const char* home = std::getenv("HOME");
    if(home == nullptr || home[0] == '\0'){
        return "";
    }

    return std::string(home) + "/.polaris_vector_history";
}
#endif

}  // namespace

int main()
{
    VectorStore vectors;
    std::cout << std::setprecision(15)
              << "Project Polaris Vector REPL (R2 and R3)\n"
              << "Type 'help' for commands or 'quit' to exit.\n";

    //#define HAVE_READLINE // for debug purposes, remove this line if you want to use readline
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

        if(!line.empty()){
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

    std::cout << "Thank you for using vector-repl - Goodbye\n";
    std::cout << "/jole 2026\n";
    return EXIT_SUCCESS;
}
