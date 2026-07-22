#include "Parser.h"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <utility>

namespace {

bool starts_number(const std::string& input, std::size_t position)
{
    const unsigned char character = static_cast<unsigned char>(input[position]);
    if(std::isdigit(character)){
        return true;
    }
    return input[position] == '.' && position + 1 < input.size() &&
           std::isdigit(static_cast<unsigned char>(input[position + 1]));
}

std::invalid_argument syntax_error(const Token& token,
                                   const std::string& expectation)
{
    return std::invalid_argument("at position " +
                                 std::to_string(token.position + 1) +
                                 ": expected " + expectation);
}

} // namespace

std::vector<Token> tokenize(const std::string& input)
{
    std::vector<Token> tokens;
    std::size_t position = 0;

    while(position < input.size()){
        const unsigned char character =
            static_cast<unsigned char>(input[position]);

        if(std::isspace(character)){
            ++position;
            continue;
        }

        if(std::isalpha(character) || input[position] == '_'){
            const std::size_t start = position++;
            while(position < input.size()){
                const unsigned char next =
                    static_cast<unsigned char>(input[position]);
                if(!std::isalnum(next) && input[position] != '_'){
                    break;
                }
                ++position;
            }
            tokens.push_back({TokenType::identifier,
                              input.substr(start, position - start), start});
            continue;
        }

        if(starts_number(input, position)){
            const std::size_t start = position;
            char* end = nullptr;
            (void)std::strtod(input.c_str() + position, &end);
            position = static_cast<std::size_t>(end - input.c_str());
            tokens.push_back({TokenType::number,
                              input.substr(start, position - start), start});
            continue;
        }

        TokenType type;
        switch(input[position]){
            case '+': type = TokenType::plus; break;
            case '-': type = TokenType::minus; break;
            case '=': type = TokenType::equals; break;
            case '(': type = TokenType::left_parenthesis; break;
            case ')': type = TokenType::right_parenthesis; break;
            case ',': type = TokenType::comma; break;
            default:
                throw std::invalid_argument(
                    "at position " + std::to_string(position + 1) +
                    ": unexpected character '" + input[position] + "'");
        }
        tokens.push_back({type, input.substr(position, 1), position});
        ++position;
    }

    tokens.push_back({TokenType::end, "", input.size()});
    return tokens;
}

Parser::Parser(std::vector<Token> tokens)
    : tokens_(std::move(tokens))
{
    if(tokens_.empty() || tokens_.back().type != TokenType::end){
        throw std::invalid_argument("a parser token sequence must end with an end token");
    }
}

const Token& Parser::current() const
{
    return tokens_[current_index_];
}

bool Parser::at(TokenType type) const
{
    return current().type == type;
}

bool Parser::match(TokenType type)
{
    if(!at(type)){
        return false;
    }
    ++current_index_;
    return true;
}

const Token& Parser::consume(TokenType type, const std::string& expectation)
{
    if(!at(type)){
        throw syntax_error(current(), expectation);
    }
    return tokens_[current_index_++];
}

void Parser::consume_end(const std::string& usage)
{
    if(!at(TokenType::end)){
        throw std::invalid_argument("usage: " + usage);
    }
}

VectorExpression Parser::parse_expression()
{
    VectorExpression expression{
        consume(TokenType::identifier, "a vector name").text, {}};

    while(at(TokenType::plus) || at(TokenType::minus)){
        VectorOperator operation = VectorOperator::add;
        if(match(TokenType::plus)){
            operation = VectorOperator::add;
        } else{
            (void)consume(TokenType::minus, "'-'");
            operation = VectorOperator::subtract;
        }

        expression.remaining.push_back({
            operation,
            consume(TokenType::identifier,
                    "a vector name after an operator").text});
    }
    return expression;
}

double Parser::parse_component()
{
    double sign = 1.0;
    if(match(TokenType::minus)){
        sign = -1.0;
    } else{
        (void)match(TokenType::plus);
    }

    const Token& number = consume(TokenType::number, "a vector component");
    const double value = sign * std::strtod(number.text.c_str(), nullptr);
    if(!std::isfinite(value)){
        throw std::invalid_argument("'" + number.text +
                                    "' is not a finite number");
    }
    return value;
}

Statement Parser::parse_vector_statement()
{
    const std::string name =
        consume(TokenType::identifier, "a vector name after 'vector'").text;

    if(match(TokenType::equals)){
        VectorExpression expression = parse_expression();
        consume_end("vector <name> = <name> [(+|-) <name> ...]");
        return VectorAssignmentStatement{name, std::move(expression)};
    }

    (void)consume(TokenType::left_parenthesis, "'(' after the vector name");
    if(at(TokenType::right_parenthesis)){
        throw std::invalid_argument("a vector must have at least one component");
    }

    std::vector<double> components;
    components.push_back(parse_component());
    while(match(TokenType::comma)){
        components.push_back(parse_component());
    }

    (void)consume(TokenType::right_parenthesis,
                  "')' after the vector components");
    consume_end("vector v(x1, x2, ..., xn)");
    return VectorLiteralStatement{name, std::move(components)};
}

Statement Parser::parse()
{
    if(at(TokenType::end)){
        return EmptyStatement{};
    }

    const Token& first = consume(TokenType::identifier, "a command or vector name");

    // An operator after the first name makes this an expression, even if the
    // name is also used as a command keyword (for example, "help - a").
    if(at(TokenType::plus) || at(TokenType::minus)){
        --current_index_;
        VectorExpression expression = parse_expression();
        consume_end("<name> (+|-) <name> [(+|-) <name> ...]");
        return ExpressionStatement{std::move(expression)};
    }

    if(first.text == "vector"){
        return parse_vector_statement();
    }
    if(first.text == "quit" || first.text == "exit"){
        consume_end("quit");
        return QuitStatement{};
    }
    if(first.text == "help"){
        consume_end("help");
        return HelpStatement{};
    }
    if(first.text == "list"){
        consume_end("list");
        return ListStatement{};
    }
    if(first.text == "show"){
        const std::string name =
            consume(TokenType::identifier, "a vector name after 'show'").text;
        consume_end("show <name>");
        return ShowStatement{name};
    }
    if(first.text == "dimension"){
        const std::string name =
            consume(TokenType::identifier, "a vector name after 'dimension'").text;
        consume_end("dimension <name>");
        return DimensionStatement{name};
    }
    if(first.text == "add"){
        const std::string first_name =
            consume(TokenType::identifier, "the first vector name").text;
        const std::string second_name =
            consume(TokenType::identifier, "the second vector name").text;
        consume_end("add <first> <second>");
        return AddStatement{first_name, second_name};
    }

    throw std::invalid_argument("unknown command '" + first.text +
                                "'; type 'help'");
}
