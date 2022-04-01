#pragma once
#include "Common.h"

class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        if (nums.size() < k)
        {
            this->nums.emplace(val);
        }
        else if (val > nums.top())
        {
            nums.pop();
            nums.emplace(val);
        }
        return nums.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> nums;
    int k;
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    EXPECT_EQ(kthLargest.add(3), 4);
    EXPECT_EQ(kthLargest.add(5), 5);
    EXPECT_EQ(kthLargest.add(10), 5);
    EXPECT_EQ(kthLargest.add(9), 8);
    EXPECT_EQ(kthLargest.add(4), 8);
}