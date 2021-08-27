#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<pair<int, int>> history;
        vector<int> result(nums.size());

        int begin = 0;
        history.emplace(nums[0], 0);
        int end = next(0, nums.size());

        while (true)
        {
            while (!history.empty() && history.top().first < nums[end])
            {
                result[history.top().second] = nums[end];
                history.pop();
            }

            if (begin == end)
            {
                while (!history.empty())
                {
                    result[history.top().second] = -1;
                    history.pop();
                }
                break;
            }

            if (history.empty())
                begin = end;
            
            history.emplace(nums[end], end);
            end = next(end, nums.size());
        }
        return result;
    }
private:
    int pre(int index, int size)
    {
        if (index == 0)
            return size - 1;
        return --index;
    }
    int next(int index, int size)
    {
        if (index == size - 1)
            return 0;
        return ++index;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 1}, output = {2, -1, 2};
    EXPECT_EQ(solution.nextGreaterElements(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 3}, output = {2, 3, 4, -1, 4};
    EXPECT_EQ(solution.nextGreaterElements(nums), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {5, 4, 3, 2, 1}, output = {-1, 5, 5, 5, 5};
    EXPECT_EQ(solution.nextGreaterElements(nums), output);
}