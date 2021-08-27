#pragma once
#include "Common.h"

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        State state = State::Default;
        for (auto c : word)
        {
            bool capital = isCapital(c);
            switch (state)
            {
            case State::Default:
                state = capital ? State::FirstCapital : State::AllNotCapital;
                break;
            case State::FirstCapital:
                state = capital ? State::AllCapital : State::AllNotCapital;
                break;
            case State::AllNotCapital:
                if (capital)
                    return false;
                break;
            case State::AllCapital:
                if (!capital)
                    return false;
                break;

            default:
                break;
            }
        }
        return true;
    }

private:
    bool isCapital(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
    enum class State
    {
        Default,
        FirstCapital,
        AllCapital,
        AllNotCapital,
        Normal,
    };
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.detectCapitalUse("USA"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.detectCapitalUse("FlaG"), false);
}