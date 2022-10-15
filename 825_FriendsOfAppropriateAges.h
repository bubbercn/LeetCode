#pragma once
#include "Common.h"

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            size_t low = -1;
            size_t high = -1;
            // case 1
            auto it = upper_bound(ages.begin(), ages.end(), (ages[i] >> 1) + 7);
            low = distance(ages.begin(), it);

            // case 2            
            it = upper_bound(ages.begin(), ages.end(), ages[i]);
            high = distance(ages.begin(), it);

            if (ages[i] < 100)
            {
                it = upper_bound(ages.begin(), ages.end(), 100);
                high = min(high, static_cast<size_t>(distance(ages.begin(), it)));
            }

            if (high > low)
            {
                result += high - low;
                if (i >= low && i < high)
                    result--;
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
    vector<int> ages = {16, 16};
    EXPECT_EQ(solution.numFriendRequests(ages), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> ages = {16, 17, 18};
    EXPECT_EQ(solution.numFriendRequests(ages), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> ages = {20, 30, 100, 110, 120};
    EXPECT_EQ(solution.numFriendRequests(ages), 3);
}