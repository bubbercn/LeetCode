#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
    vector<int> output = {3, 4};
    EXPECT_EQ(solution.exclusiveTime(2, logs), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> logs = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
    vector<int> output = {8};
    EXPECT_EQ(solution.exclusiveTime(1, logs), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> logs = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
    vector<int> output = {7, 1};
    EXPECT_EQ(solution.exclusiveTime(2, logs), output);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<string> logs = {"0:start:0", "0:start:2", "0:end:5", "1:start:7", "1:end:7", "0:end:8"};
    vector<int> output = {8, 1};
    EXPECT_EQ(solution.exclusiveTime(2, logs), output);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<string> logs = {"0:start:0", "0:end:0"};
    vector<int> output = {1};
    EXPECT_EQ(solution.exclusiveTime(1, logs), output);
}