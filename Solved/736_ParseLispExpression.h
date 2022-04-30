#pragma once
#include "Common.h"

class Solution
{
public:
    int evaluate(string_view expression)
    {
        return evaluate(expression, 0).first;
    }

private:
    enum class TokenType
    {
        Integer,
        Variable,
        Let,
        Add,
        Mult,
        End,
        Invalid,
    };

    unordered_map<string_view, stack<int>> parameters;

    pair<int, size_t> evaluate(string_view expression, size_t startPos)
    {
        auto [tokenType, value, nextPos] = parseNextToken(expression, startPos);

        if (tokenType == TokenType::Integer)
            return {stoi(string(value)), nextPos};

        if (tokenType == TokenType::Add)
            return add(expression, nextPos);

        if (tokenType == TokenType::Mult)
            return mult(expression, nextPos);

        if (tokenType == TokenType::Let)
            return let(expression, nextPos);

        if (tokenType == TokenType::Variable)
            return {parameters[value].top(), nextPos};

        assert(false);
        return {0, -1};
    }

    pair<string_view, size_t> getNextToken(string_view expression, size_t startPos)
    {
        if (size_t pos = expression.find_first_of(" )", startPos); pos == string::npos)
        {
            return {expression.substr(startPos), pos};
        }
        else
        {
            return {expression.substr(startPos, pos - startPos), pos};
        }
    }

    TokenType string2TokenType(string_view op)
    {
        if (op == "add")
        {
            return TokenType::Add;
        }
        else if (op == "mult")
        {
            return TokenType::Mult;
        }
        else if (op == "let")
        {
            return TokenType::Let;
        }
        else
        {
            assert(false);
            return TokenType::Invalid;
        }
    }

    tuple<TokenType, string_view, size_t> parseNextToken(string_view expression, size_t startPos)
    {
        assert(startPos < expression.length());
        while (expression[startPos] == ' ')
        {
            startPos++;
        }
        if (expression[startPos] == '-' || (expression[startPos] >= '0' && expression[startPos] <= '9'))
        {
            auto [value, nextPos] = getNextToken(expression, startPos);
            return {TokenType::Integer, value, nextPos};
        }

        if (expression[startPos] == '(')
        {
            startPos++;
            auto [op, nextPos] = getNextToken(expression, startPos);
            TokenType type = string2TokenType(op);
            return {type, op, nextPos};
        }

        auto [variable, nextPos] = getNextToken(expression, startPos);
        return {TokenType::Variable, variable, nextPos};
    }

    pair<int, size_t> add(string_view expression, size_t startPos)
    {
        auto [value1, nextPos1] = evaluate(expression, startPos);
        auto [value2, nextPos2] = evaluate(expression, nextPos1);
        return {value1 + value2, nextPos2 + 1};
    }

    pair<int, size_t> mult(string_view expression, size_t startPos)
    {
        auto [value1, nextPos1] = evaluate(expression, startPos);
        auto [value2, nextPos2] = evaluate(expression, nextPos1);
        return {value1 * value2, nextPos2 + 1};
    }

    pair<int, size_t> let(string_view expression, size_t startPos)
    {
        list<string_view> parameterList;
        while (true)
        {
            auto [type, token, nextPos1] = parseNextToken(expression, startPos);
            if (type != TokenType::Variable || expression[nextPos1] == ')')
                break;

            startPos = nextPos1;
            auto [value, nextPos2] = evaluate(expression, startPos);
            startPos = nextPos2;
            parameterList.emplace_back(token);
            parameters[token].emplace(value);
        }
        auto result = evaluate(expression, startPos);
        for (auto &parameter : parameterList)
        {
            stack<int> &values = parameters[parameter];
            values.pop();
            if (values.empty())
            {
                parameters.erase(parameter);
            }
        }
        return {result.first, result.second + 1};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"), 14);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.evaluate("(let x 3 x 2 x)"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.evaluate("(let x 1 y 2 x (add x y) (add x y))"), 5);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.evaluate("-1"), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))"), 6);
}