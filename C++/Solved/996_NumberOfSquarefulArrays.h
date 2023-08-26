#pragma once
#include "Common.h"

class Solution
{
public:
    int numSquarefulPerms(vector<int> &nums)
    {
        unordered_map<int, int> numsMap;
        unordered_map<int, unordered_set<int>> next;
        for (int i = 0; i < nums.size(); i++)
        {
            numsMap[nums[i]]++;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (isPerfectSquare(nums[i] + nums[j]))
                {
                    next[nums[i]].emplace(nums[j]);
                    next[nums[j]].emplace(nums[i]);
                }
            }
            next[-1].emplace(nums[i]);
        }
        return dfs(-1, numsMap, next);
    }

private:
    int dfs(int pre, unordered_map<int, int> &nums, const unordered_map<int, unordered_set<int>> &next)
    {
        auto it = next.find(pre);
        if (it == next.end())
            return 0;

        if (nums.empty())
            return 1;

        int result = 0;
        for (auto num : it->second)
        {
            auto i = nums.find(num);
            if (i == nums.end())
                continue;

            i->second--;
            if (i->second == 0)
                nums.erase(i);

            result += dfs(num, nums, next);

            nums[num]++;
        }
        return result;
    }

    bool isPerfectSquare(int n)
    {
        int squre = sqrt(n);
        return n == squre * squre;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 17, 8};
    EXPECT_EQ(solution.numSquarefulPerms(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 2};
    EXPECT_EQ(solution.numSquarefulPerms(nums), 1);
}
