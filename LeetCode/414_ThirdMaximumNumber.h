#pragma once
#include "Common.h"

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        vector<int> result(3, numeric_limits<int>::min());
        int min = numeric_limits<int>::max();
        for (auto i : nums)
        {
            min = ::min(i, min);

            if (i <= result[2] || i == result[0] || i == result[1])
                continue;

            if (i > result[0])
            {
                result[2] = result[1];
                result[1] = result[0];
                result[0] = i;
            }
            else if (i > result[1])
            {
                result[2] = result[1];
                result[1] = i;
            }
            else
            {
                result[2] = i;
            }
        }
        
        if (result[1] == numeric_limits<int>::min())
            return result[0];
        
        if (result[2] == numeric_limits<int>::min() && min != numeric_limits<int>::min())
            return result[0];
        
        return result[2];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {3, 2, 1};
    EXPECT_EQ(solution.thirdMax(nums), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2};
    EXPECT_EQ(solution.thirdMax(nums), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, 2, 3, 1};
    EXPECT_EQ(solution.thirdMax(nums), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 2, -2147483648};
    EXPECT_EQ(solution.thirdMax(nums), -2147483648);
}