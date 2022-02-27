#pragma once
#include "Common.h"

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int avg = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (*nums.rbegin() > avg)
            return false;
        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, 0, avg, avg, k);
    }

private:
    bool dfs(const vector<int> &nums, vector<bool>& visited, int startIndex, int target, int remain, int k)
    {
        if (k == 1)
            return true;

        int pre = -1;

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (visited[i])
                continue;

            if (nums[i] > remain)
                continue;

            if (pre != -1 && nums[pre] == nums[i])
                continue;

            visited[i] = true;
            bool temp = false;
            if (nums[i] == remain)
            {
                temp = dfs(nums, visited, 0, target, target, k - 1);
                visited[i] = false;
                return temp;
            }

            pre = i;
            temp = dfs(nums, visited, i + 1, target, remain - nums[i], k);
            visited[i] = false;
            if (temp)
                return true;
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
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    EXPECT_EQ(solution.canPartitionKSubsets(nums, 4), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.canPartitionKSubsets(nums, 3), false);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> nums = {2999, 3914, 1064, 927, 64, 1130, 2048, 235, 159, 3549, 241, 987, 972, 976, 279, 1004};
    EXPECT_EQ(solution.canPartitionKSubsets(nums, 4), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 2};
    EXPECT_EQ(solution.canPartitionKSubsets(nums, 4), true);
}
