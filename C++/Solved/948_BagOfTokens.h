#pragma once
#include "Common.h"

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int begin = 0;
        int end = n - 1;
        int result = 0;
        while (begin <= end)
        {
            if (power >= tokens[begin])
            {
                result++;
                power -= tokens[begin];
                begin++;
            }
            else if (result > 0 and end - begin > 0 and power + tokens[end] >= tokens[begin])
            {
                power += tokens[end] - tokens[begin];
                begin++;
                end--;
            }
            else
            {
                break;
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
    vector<int> tokens = {100};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 50), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> tokens = {100, 200};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 150), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> tokens = {100, 200, 300, 400};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 200), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> tokens = {71, 55, 82};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 54), 0);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> tokens = {6, 0, 39, 52, 45, 49, 59, 68, 42, 37};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 99), 5);
}