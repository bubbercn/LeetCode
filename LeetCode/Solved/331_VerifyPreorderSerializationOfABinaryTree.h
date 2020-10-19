#pragma once
#include "Common.h"

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        if (preorder.empty())
            return false;

        int nodeCount = 1;

        char *input = &preorder[0];
        char *token;

        token = strtok(input, ",");
        while (token != nullptr)
        {
            nodeCount--;
            if (nodeCount < 0)
                return false;
            if (strcmp("#", token) != 0)
                nodeCount += 2;

            token = strtok(nullptr, ",");
        }

        return nodeCount == 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isValidSerialization("1,#"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isValidSerialization("9,#,#,1"), false);
}

TEST_F(LeetCodeTest, Empty)
{
    EXPECT_EQ(solution.isValidSerialization(""), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.isValidSerialization("9,#,92,#,#"), true);
}