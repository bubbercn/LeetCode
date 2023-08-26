#pragma once
#include "Common.h"

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        vector<int> count(101);
        for (auto num : arr)
        {
            count[num]++;
        }
        int result = 0;
        for (int i = 0; i <= 100; i++)
        {
            if (count[i] == 0)
                continue;
            for (int j = i; j <= 100; j++)
            {
                if (count[j] == 0 || (j == i && count[j] == 1))
                    continue;

                int k = target - i - j;
                if (k < j || k > 100)
                    continue;

                int temp = count[k];
                if (k == i)
                    temp;
                if (k == j)
                    temp;
                if (temp <= 0)
                    continue;

                unordered_map<int, int> lookup;
                lookup[i]++;
                lookup[j]++;
                lookup[k]++;

                int x = 1;
                for (auto [v, c] : lookup)
                {
                    x *= C(count[v], c);
                }

                result = (result + x) % MOD;
            }
        }
        return result;
    }

private:
    static constexpr int MOD = 1000000000 + 7;
    int C(int m, int n)
    {
        long result = P(m, n) / P(n, n);
        return result % MOD;
    }
    long P(int m, int n)
    {
        long result = m--;
        while (--n > 0)
        {
            result *= m--;
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
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    EXPECT_EQ(solution.threeSumMulti(arr, 8), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 1, 2, 2, 2, 2};
    EXPECT_EQ(solution.threeSumMulti(arr, 5), 12);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {2, 1, 3};
    EXPECT_EQ(solution.threeSumMulti(arr, 6), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> arr = {0, 2, 0, 0};
    EXPECT_EQ(solution.threeSumMulti(arr, 2), 3);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> arr = {92, 4, 59, 23, 100, 16, 7, 15, 3, 78, 98, 17, 77, 33, 83, 15, 87, 35, 54, 72, 58, 14, 87, 47, 58, 31, 72, 58, 87, 22, 25, 54, 27, 53, 13, 54, 61, 12, 96, 24, 35, 43, 94, 1, 88, 76, 89, 89, 41, 56, 61, 65, 60, 91, 89, 79, 86, 52, 27, 2, 97, 46, 50, 46, 87, 93, 71, 87, 95, 78, 65, 10, 35, 51, 34, 66, 61, 7, 49, 38, 10, 1, 88, 37, 50, 84, 35, 20, 7, 83, 51, 85, 11, 12, 89, 93, 54, 23, 36, 95, 100, 19, 82, 67, 96, 77, 53, 56, 51, 16, 54, 7, 30, 68, 78, 13, 38, 52, 91, 44, 54, 17, 21, 44, 4, 10, 85, 19, 11, 88, 73, 36, 47, 53, 3, 21, 41, 24, 60, 53, 88, 35, 48, 89, 35, 3, 43, 85, 45, 67, 56, 78, 44, 49, 29, 35, 68, 96, 29, 21, 51, 17, 52, 99, 3, 48, 65, 51, 22, 38, 77, 81, 30, 64, 99, 35, 88, 72, 73, 29, 29, 2};
    EXPECT_EQ(solution.threeSumMulti(arr, 105), 5166);
}