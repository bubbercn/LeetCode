#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> diStringMatch(string_view s)
    {
        int n = s.length() + 1;
        int low = 0;
        int up = n - 1;
        vector<int> result(n);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'D')
            {
                result[i] = up--;
            }
            else
            {
                result[i] = low++;
            }
        }
        result[n - 1] = low;
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
    vector<int> output = {0, 4, 1, 3, 2};
    EXPECT_EQ(solution.diStringMatch("IDID"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {0, 1, 2, 3};
    EXPECT_EQ(solution.diStringMatch("III"), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> output = {3, 2, 0, 1};
    EXPECT_EQ(solution.diStringMatch("DDI"), output);
}