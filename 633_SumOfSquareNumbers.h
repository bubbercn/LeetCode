#pragma once
#include "Common.h"

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        vector<int> nums;
        long temp;
        for (long i = 0; (temp = i * i) <= c; i++)
        {
            nums.emplace_back(temp);
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            temp = static_cast<long>(nums[left]) + nums[right];
            if (temp == c)
                return true;
            
            if (temp < c)
                left++;
            else
                right--;
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.judgeSquareSum(5), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.judgeSquareSum(3), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.judgeSquareSum(4), true);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.judgeSquareSum(2), true);
}

TEST_F(LeetCodeTest, Example5)
{
    EXPECT_EQ(solution.judgeSquareSum(1), true);
}