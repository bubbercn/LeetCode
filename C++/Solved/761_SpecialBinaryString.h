#pragma once
#include "Common.h"

class Solution
{
public:
    string makeLargestSpecial(string_view s)
    {
        using StringSet = multiset<string, greater<string>>;
        stack<StringSet> stateStack;
        stateStack.emplace(StringSet());
        for (auto c : s)
        {
            if (c == '1')
            {
                stateStack.emplace(StringSet());
            }
            else
            {
                string temp = "1";
                for (auto &s : stateStack.top())
                {
                    temp += s;
                }
                temp += '0';
                stateStack.pop();
                stateStack.top().emplace(temp);
            }
        }
        string result;
        for (auto &s : stateStack.top())
        {
            result += s;
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
    EXPECT_EQ(solution.makeLargestSpecial("11011000"), "11100100");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.makeLargestSpecial("10"), "10");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.makeLargestSpecial("101010"), "101010");
}