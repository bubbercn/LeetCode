#pragma once
#include "Common.h"

struct Complex
{
    int real;
    int imaginary;
    void fromString(string_view input)
    {
        int plus = input.find_first_of('+');
        real = stoi(input.substr(0, plus).data());
        int i = input.find_last_of('i');
        imaginary = stoi(input.substr(plus + 1, i - plus - 1).data());
    }
    string toString() const
    {
        stringstream output;
        output << real << '+' << imaginary << 'i';
        return output.str();
    }
};

Complex multiply(const Complex& c1, const Complex& c2)
{
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c2.real * c1.imaginary;
    return result;
}

class Solution
{
public:
    string complexNumberMultiply(string_view num1, string_view num2)
    {
        Complex c1, c2;
        c1.fromString(num1);
        c2.fromString(num2);
        return multiply(c1, c2).toString();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    string num1 = "1+1i";
    string num2 = "1+1i";
    EXPECT_EQ(solution.complexNumberMultiply(num1, num2), "0+2i");
}

TEST_F(LeetCodeTest, Example2)
{
    string num1 = "1+-1i";
    string num2 = "1+-1i";
    EXPECT_EQ(solution.complexNumberMultiply(num1, num2), "0+-2i");
}