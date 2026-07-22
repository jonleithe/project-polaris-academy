#include "Parser.h"

#include <cstdlib>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

namespace {

void expect(bool condition, const char* message)
{
    if(!condition){
        throw std::runtime_error(message);
    }
}

template <typename Operation>
void expect_parse_error(Operation operation, const char* message)
{
    try {
        operation();
    } catch(const std::invalid_argument&){
        return;
    }
    throw std::runtime_error(message);
}

Statement parse(const std::string& input)
{
    Parser parser(tokenize(input));
    return parser.parse();
}

} // namespace

int main()
{
    const std::vector<Token> tokens = tokenize("vector a(-1, 2.5)");
    expect(tokens.size() == 9, "token count is incorrect");
    expect(tokens[0].type == TokenType::identifier &&
           tokens[0].text == "vector", "command token is incorrect");
    expect(tokens[2].type == TokenType::left_parenthesis,
           "left parenthesis token is incorrect");
    expect(tokens[3].type == TokenType::minus,
           "minus token is incorrect");
    expect(tokens.back().type == TokenType::end,
           "end token is missing");

    const Statement literal_result = parse("vector position(-1, 2.5, 3e2)");
    const auto* literal = std::get_if<VectorLiteralStatement>(&literal_result);
    expect(literal != nullptr, "vector literal statement was not parsed");
    expect(literal->name == "position", "vector literal name is incorrect");
    expect(literal->components.size() == 3 &&
           literal->components[0] == -1.0 &&
           literal->components[1] == 2.5 &&
           literal->components[2] == 300.0,
           "vector literal components are incorrect");

    const Statement assignment_result = parse("vector total = a+b - c");
    const auto* assignment =
        std::get_if<VectorAssignmentStatement>(&assignment_result);
    expect(assignment != nullptr, "vector assignment was not parsed");
    expect(assignment->name == "total", "assignment target is incorrect");
    expect(assignment->expression.first == "a",
           "assignment first operand is incorrect");
    expect(assignment->expression.remaining.size() == 2 &&
           assignment->expression.remaining[0].operation == VectorOperator::add &&
           assignment->expression.remaining[0].name == "b" &&
           assignment->expression.remaining[1].operation ==
               VectorOperator::subtract &&
           assignment->expression.remaining[1].name == "c",
           "assignment operations are incorrect");

    const Statement expression_result = parse("a - b + c");
    const auto* expression =
        std::get_if<ExpressionStatement>(&expression_result);
    expect(expression != nullptr, "vector expression was not parsed");
    expect(expression->expression.first == "a",
           "expression first operand is incorrect");
    expect(expression->expression.remaining.size() == 2 &&
           expression->expression.remaining[0].operation ==
               VectorOperator::subtract &&
           expression->expression.remaining[0].name == "b" &&
           expression->expression.remaining[1].operation == VectorOperator::add &&
           expression->expression.remaining[1].name == "c",
           "expression operations are incorrect");

    const Statement show_result = parse("show position");
    const auto* show = std::get_if<ShowStatement>(&show_result);
    expect(show != nullptr && show->name == "position",
           "show statement is incorrect");

    expect(std::holds_alternative<EmptyStatement>(parse("   ")),
           "empty input is incorrect");
    expect(std::holds_alternative<QuitStatement>(parse("exit")),
           "exit alias is incorrect");

    expect_parse_error([] { (void)parse("vector empty()"); },
                       "empty vector literal was accepted");
    expect_parse_error([] { (void)parse("vector a(1,,2)"); },
                       "missing vector component was accepted");
    expect_parse_error([] { (void)parse("a +"); },
                       "incomplete addition was accepted");
    expect_parse_error([] { (void)parse("a -"); },
                       "incomplete subtraction was accepted");
    expect_parse_error([] { (void)parse("show a b"); },
                       "extra command argument was accepted");
    expect_parse_error([] { (void)parse("vector a(1; 2)"); },
                       "unknown punctuation was accepted");

    return EXIT_SUCCESS;
}
