#pragma once
#include "Common.h"

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
private:
    int atMostK(vector<int> &nums, int k)
    {
        if (k == 0)
            return 0;
        
        unordered_map<int, int> count;
        int result = 1;
        int left = 0;
        int right = 1;
        count[nums[0]]++;
        while (right < nums.size())
        {
            count[nums[right]]++;
            while (count.size() > k)
            {
                count[nums[left]]--;
                if (count[nums[left]] == 0)
                    count.erase(nums[left]);
                left++;
            }
            result += right - left + 1;
            right++;
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
    vector<int> nums = {1, 2, 1, 2, 3};
    EXPECT_EQ(solution.subarraysWithKDistinct(nums, 2), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 1, 3, 4};
    EXPECT_EQ(solution.subarraysWithKDistinct(nums, 3), 3);
}