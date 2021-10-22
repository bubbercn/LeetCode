#pragma once
#include "Common.h"

class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        lookup.clear();
        return helper(nums, 0).first;
    }

private:
    pair<string, double> helper(vector<int> &nums, int start)
    {
        if (start == nums.size() - 1)
            return {to_string(nums[start]), nums[start]};
        
        if (start == nums.size() - 2)
        {
            string s = to_string(nums[start]) + "/" + to_string(nums[start + 1]);
            double v = static_cast<double>(nums[start]) / nums[start + 1];
            if (start == 0)
                return {s, v};
            
            s = "(" + s + ")";
            lookup.insert({start, {s, v}});
            return {s, v};
        }

        if (auto it = lookup.find(start); it != lookup.end())
            return it->second;

        
    }
    unordered_map<int, pair<string, double>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1000, 100, 10, 2};
    EXPECT_EQ(solution.optimalDivision(nums), "1000/(100/10/2)");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 3, 4};
    EXPECT_EQ(solution.optimalDivision(nums), "2/(3/4)");
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2};
    EXPECT_EQ(solution.optimalDivision(nums), "2");
}