#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        result.clear();
        result.reserve(n);
        this->n = n;
        for (int i = 1; i < 10; i++)
        {
            helper(i);
        }
        return result;
    }

private:
    void helper(int root)
    {
        if (root > n)
            return;

        result.emplace_back(root);
        for (int i = 0; i < 10; i++)
        {
            helper(root * 10 + i);
        }
    }
    vector<int> result;
    int n;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(solution.lexicalOrder(13), output);
}
