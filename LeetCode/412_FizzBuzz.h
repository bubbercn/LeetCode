#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result(n);
        for (int i = 0; i < n; i++)
        {
            int num = i + 1;
            bool isFizz = (num % 3 == 0);
            bool isBuzz = (num % 5 == 0);
            if (isFizz)
            {
                if (isBuzz)
                {
                    result[i] = "FizzBuzz";
                }
                else
                {
                    result[i] = "Fizz";
                }
            }
            else if (isBuzz)
            {
                result[i] = "Buzz";
            }
            else
            {
                result[i] = to_string(num);
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> output = {
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz",
    };
    EXPECT_EQ(solution.fizzBuzz(15), output);
}
