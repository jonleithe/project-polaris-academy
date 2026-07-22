/*******************************************************************************
file    : Parser.h
author  : jole
date    : 2026-07-22
*******************************************************************************/
#pragma once

#include <cstddef>
#include <string>
#include <variant>
#include <vector>



enum class TokenType {
    identifier,
    number,
    plus,
    minus,
    equals,
    left_parenthesis,
    right_parenthesis,
    comma,
    end
};



struct Token {
    TokenType type;
    std::string text;
    std::size_t position;
};



[[nodiscard]] std::vector<Token> tokenize(const std::string& input);

struct EmptyStatement {};
struct QuitStatement {};
struct HelpStatement {};
struct ListStatement {};

struct ShowStatement {
    std::string name;
};

struct DimensionStatement {
    std::string name;
};

struct AddStatement {
    std::string first;
    std::string second;
};

struct VectorLiteralStatement {
    std::string name;
    std::vector<double> components;
};

enum class VectorOperator {
    add,
    subtract
};

struct ExpressionTerm {
    VectorOperator operation;
    std::string name;
};

struct VectorExpression {
    std::string first;
    std::vector<ExpressionTerm> remaining;
};

struct VectorAssignmentStatement {
    std::string name;
    VectorExpression expression;
};

struct ExpressionStatement {
    VectorExpression expression;
};

using Statement = std::variant<EmptyStatement,
                               QuitStatement,
                               HelpStatement,
                               ListStatement,
                               ShowStatement,
                               DimensionStatement,
                               AddStatement,
                               VectorLiteralStatement,
                               VectorAssignmentStatement,
                               ExpressionStatement>;

class Parser{
    
public:
    explicit Parser(std::vector<Token> tokens);

    [[nodiscard]] Statement parse();

private:
    [[nodiscard]] const Token& current() const;
    [[nodiscard]] bool at(TokenType type) const;
    [[nodiscard]] bool match(TokenType type);
    [[nodiscard]] const Token& consume(TokenType type,
                                       const std::string& expectation);
    void consume_end(const std::string& usage);

    [[nodiscard]] Statement parse_vector_statement();
    [[nodiscard]] VectorExpression parse_expression();
    [[nodiscard]] double parse_component();

    std::vector<Token> tokens_;
    std::size_t current_index_ = 0;
};
