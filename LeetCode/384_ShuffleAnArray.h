#pragma once
#include "Common.h"

class Solution
{
public:
    Solution(vector<int> &nums) : nums(nums)
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> temp(nums);
        mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        for (int i = 0; i < temp.size(); i++)
        {
            uniform_int_distribution<> distrib(i, temp.size() - 1);
            swap(temp[i], temp[distrib(gen)]);
        }
        return temp;
    }

private:
    vector<int> nums;
    random_device rd;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3};
    Solution solution(nums);
    solution.shuffle(); // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
    EXPECT_EQ(solution.reset(), nums);
    solution.shuffle(); // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
}
