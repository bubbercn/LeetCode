#pragma once
#include "Common.h"

class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        double avg = static_cast<double>(sum) / n;
        vector<double> nums1((n + 1) / 2, 0);
        vector<double> nums2(n - nums1.size(), 0);
        for (int i = 0; i < n; i++)
        {
            if (i < nums1.size())
            {
                nums1[i] = nums[i] - avg;
            }
            else
            {
                nums2[i - nums1.size()] = nums[i] - avg;
            }
        }
        vector<double> sums1 = getSums(nums1);
        vector<double> sums2 = getSums(nums2);

        for (int i = 1; i < sums1.size(); i++)
        {
            if (isZero(sums1[i]))
                return true;
        }
        for (int i = 1; i < sums2.size(); i++)
        {
            if (isZero(sums2[i]))
                return true;
        }

        sums1.erase(sums1.begin());
        sums1.pop_back();
        sums2.erase(sums2.begin());
        sums2.pop_back();

        sort(sums1.begin(), sums1.end());
        sort(sums2.begin(), sums2.end());

        int i1 = sums1.size() - 1, i2 = 0;
        while (i1 >= 0 && i2 < sums2.size())
        {
            double temp = sums1[i1] + sums2[i2];
            if (isZero(temp))
                return true;
            else if (temp > 0)
                i1--;
            else
                i2++;
        }

        return false;
    }

private:
    bool isZero(double v)
    {
        return fabs(v) < 1e-5;
    }

    vector<double> getSums(const vector<double> &nums)
    {
        int n = nums.size();
        vector<double> result(1 << n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < (1 << i); ++j)
            {
                result[j + (1 << i)] = result[j] + nums[i];
            }
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(solution.splitArraySameAverage(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 1};
    EXPECT_EQ(solution.splitArraySameAverage(nums), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {18, 0, 16, 2};
    EXPECT_EQ(solution.splitArraySameAverage(nums), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> nums = {5, 3, 11, 19, 2};
    EXPECT_EQ(solution.splitArraySameAverage(nums), true);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<int> nums = {10, 29, 13, 53, 33, 48, 76, 70, 5, 5};
    EXPECT_EQ(solution.splitArraySameAverage(nums), true);
}