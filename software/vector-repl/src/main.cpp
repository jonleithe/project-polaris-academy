#include "RVector.h"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#if defined(HAVE_READLINE)
    // CMake defines HAVE_READLINE only when the optional library is found.
    // The preprocessor removes this code entirely in builds without Readline.
    #include <readline/history.h>
    #include <readline/readline.h>
#endif



namespace {

// A type alias gives a domain-specific name to a fairly verbose template type.
// unordered_map is a hash table owning string keys and RVector values.
using VectorStore = std::unordered_map<std::string, RVector>;

// This unnamed namespace gives all helpers in it internal linkage: they are
// private to this translation unit and cannot collide with names in other .cpps.

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
        << "  <expression>                Example: -4*a + 3*b - c\n"
        << "  list                        Show all stored vectors\n"
        << "  help                        Show this help\n"
        << "  quit                        Exit\n";
}



double parse_number(const std::string& text)
{
    std::size_t parsed = 0;
    // stod converts the numeric prefix and writes the number of consumed
    // characters through &parsed. Checking both conditions rejects "12oops",
    // infinity, and NaN rather than quietly accepting them.
    const double value = std::stod(text, &parsed);
    if(parsed != text.size() || !std::isfinite(value)){
        throw std::invalid_argument("'" + text + "' is not a finite number");
    }
    return value;
}



const RVector& find_vector(const VectorStore& vectors, const std::string& name)
{
    // auto asks the compiler to infer the iterator's long concrete type.
    const auto found = vectors.find(name);
    if(found == vectors.end()){
        throw std::invalid_argument("no vector named '" + name + "'");
    }
    // Map iterators point to key/value pairs: first is the key, second the value.
    // Returning const RVector& avoids a copy and prevents callers from mutation.
    // The reference remains valid here because the map outlives command handling.
    return found->second;
}



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



RVector evaluate_vector_term(const std::string& text,
                             double sign,
                             const VectorStore& vectors)
{
    const std::size_t multiply = text.find('*');
    if(multiply != std::string::npos &&
       text.find('*', multiply + 1) != std::string::npos){
        throw std::invalid_argument(
            "a term must have the form [number *] name");
    }

    double scalar = sign;
    std::string vector_name = trim(text);
    if(multiply != std::string::npos){
        const std::string scalar_text = trim(text.substr(0, multiply));
        vector_name = trim(text.substr(multiply + 1));
        if(scalar_text.empty()){
            throw std::invalid_argument(
                "a term must have the form [number *] name");
        }
        scalar *= parse_number(scalar_text);
    }

    if(vector_name.empty()){
        throw std::invalid_argument(
            "a term must have the form [number *] name");
    }

    return scalar * find_vector(vectors, vector_name);
}



bool try_run_vector_expression(const std::string& line,
                               const VectorStore& vectors)
{
    // An operator distinguishes an expression from an unknown one-word command.
    if(line.find('*') == std::string::npos &&
       line.find('+') == std::string::npos &&
       line.find('-') == std::string::npos){
        return false;
    }

    std::optional<RVector> result;
    std::size_t position = 0;

    while(position < line.size()){
        while(position < line.size() &&
              std::isspace(static_cast<unsigned char>(line[position]))){
            ++position;
        }

        double sign = 1.0;
        if(position < line.size() &&
           (line[position] == '+' || line[position] == '-')){
            sign = line[position] == '-' ? -1.0 : 1.0;
            ++position;
        }

        const std::size_t term_start = position;
        while(position < line.size()){
            const char current = line[position];
            if((current == '+' || current == '-') && position > term_start){
                // A sign following e/E belongs to scientific notation, as in
                // 1e-3*a, rather than separating two vector terms.
                const char previous = line[position - 1];
                if(previous != 'e' && previous != 'E'){
                    break;
                }
            }
            ++position;
        }

        const std::string term_text = trim(line.substr(term_start,
                                                       position - term_start));
        if(term_text.empty()){
            throw std::invalid_argument("expected a vector term");
        }

        const RVector term = evaluate_vector_term(term_text, sign, vectors);
        if(result.has_value()){
            result = *result + term;
        } else{
            result = term;
        }
    }

    if(!result.has_value()){
        throw std::invalid_argument("expected a vector expression");
    }

    std::cout << *result << '\n';
    return true;
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
    // arguments is read-only, while vectors is a non-const reference because the
    // "vector" command may change the caller's store. References cannot be null.
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
        // insert_or_assign (C++17) handles both a new name and replacement.
        // Moving components hands off its allocation because it is finished here.
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
            // Structured binding (C++17) names the two fields in each map entry.
            // const auto& avoids copying either the stored string or RVector.
            for(const auto& [name, vector] : vectors){
                std::cout << name << " = " << vector << '\n';
            }
        }
    } else{
        throw std::invalid_argument("unknown command '" + command + "'; type 'help'");
    }
}



bool is_command(const std::string& word)
{
    return word == "help" || word == "vector" || word == "magnitude" ||
           word == "scale" || word == "add" || word == "subtract" ||
           word == "dot" || word == "cross" || word == "list";
}



bool process_line(const std::string& line, VectorStore& vectors)
{
    // Streams can tokenize a string using the familiar >> extraction syntax.
    // Both local containers clean up automatically on every return or exception.
    std::istringstream input(line);
    std::vector<std::string> arguments;
    // C++ permits a declaration in the for-loop initializer. Extraction is the
    // condition: the loop ends when there are no more whitespace-delimited words.
    for(std::string argument; input >> argument;){
        // Each argument is disposable after insertion, so moving may reuse its
        // character buffer. push_back grows the vector automatically.
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

    // Exceptions separate error detection deep in parsing/vector operations from
    // the single user-facing error boundary here. Catch by const reference avoids
    // copying and preserves polymorphic exception behavior.
    try {
        if(is_command(arguments.front())){
            run_command(arguments, vectors);
        } else if(!try_run_vector_expression(line, vectors)){
            run_command(arguments, vectors);
        }
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
    }

    return false;
}



#if defined(HAVE_READLINE)
std::string history_file_path()
{
    // getenv is a C API returning a borrowed pointer; it may return nullptr.
    // We copy its contents into std::string rather than trying to own/free it.
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
    // Automatic objects have deterministic lifetimes. vectors is destroyed and
    // releases all its memory when main exits, including on ordinary early exits.
    VectorStore vectors;
    // Stream manipulators such as setprecision configure subsequent output.
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
        // Readline is a C library and returns malloc-allocated char*. This is one
        // place modern automatic ownership is unavailable, so every successful
        // call must be paired with free(). nullptr signals end-of-file.
        char* input_line = readline("polaris> ");
        if(input_line == nullptr){
            std::cout << '\n';
            break;
        }

        // First copy into an owning std::string, then release the C allocation.
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
    // operator&& short-circuits. The prompt is written first; getline then reads
    // a complete line and converts to false on EOF or an input error.
    while(std::cout << "polaris> " && std::getline(std::cin, line)){
        if(process_line(line, vectors)){
            break;
        }
    }
    #endif

    std::cout << "Thank you for using vector-repl - Goodbye\n";
    std::cout << "/jole 2026\n";
    // EXIT_SUCCESS is a portable success status supplied by <cstdlib>.
    return EXIT_SUCCESS;
}
