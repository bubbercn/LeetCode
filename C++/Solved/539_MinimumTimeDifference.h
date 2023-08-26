#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        if (timePoints.size() >= 1440)
            return 0;

        unordered_set<int> times;
        for (auto &timePoint : timePoints)
        {
            if (!times.emplace(time2Int(timePoint)).second)
                return 0;
        }
        for (int result = 1; result <= 720; result++)
        {
            for (auto time : times)
            {
                int x = time + result;
                if (x >= 1440)
                    x -= 1440;
                if (times.count(x) != 0)
                    return result;
                x = time - result;
                if (x < 0)
                    x += 1440;
                if (times.count(x) != 0)
                    return result;
            }
        }
        return -1;
    }

private:
    int time2Int(string_view input)
    {
        int h = stoi(input.substr(0, 2).data());
        int m = stoi(input.substr(3, 2).data());
        return h * 60 + m;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> timePoints = {"23:59", "00:00"};
    EXPECT_EQ(solution.findMinDifference(timePoints), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> timePoints = {"00:00", "23:59", "00:00"};
    EXPECT_EQ(solution.findMinDifference(timePoints), 0);
}