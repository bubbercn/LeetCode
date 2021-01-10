#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        if (num > 10 || num < 0)
            return {};
        vector<string> result;
        int hourLimit = min(num, 4);
        for (int i = 0; i <= num; i++)
        {
            vector<string> hours = getHours(i);
            vector<string> mins = getMins(num - i);
            for (auto &hour : hours)
            {
                for (auto &min : mins)
                {
                    result.emplace_back(hour + ":" + min);
                }
            }
        }
        return result;
    }

private:
    vector<string> getHours(int n)
    {
        if (n > 4)
            return {};
        vector<int> values = helper(4, n);
        vector<string> result;
        result.reserve(values.size());
        for (auto value : values)
        {
            if (value >= 12)
                continue;
            result.emplace_back(to_string(value));
        }
        return result;
    }
    vector<string> getMins(int n)
    {
        if (n > 6)
            return {};
        vector<int> values = helper(6, n);
        vector<string> result;
        result.reserve(values.size());
        for (auto value : values)
        {
            if (value > 59)
                continue;
            stringstream temp;
            temp << setw(2) << setfill('0') << value;
            result.emplace_back(temp.str());
        }
        return result;
    }
    vector<int> helper(int numOfBits, int numOf1)
    {
        if (numOf1 > numOfBits)
            return {};

        if (numOf1 == 0)
            return {0};

        vector<int> result;
        for (int i = numOfBits - 1; i >= 0; i--)
        {
            vector<int> values = helper(i, numOf1 - 1);
            for (auto value : values)
            {
                result.emplace_back(value | (1 << i));
            }
        }

        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static set<string> output;
};

TEST_F(LeetCodeTest, Example1)
{
    output = {"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"};
    auto temp = solution.readBinaryWatch(1);
    set<string> result(temp.begin(), temp.end());
    EXPECT_EQ(result, output);
}

TEST_F(LeetCodeTest, Case2)
{
    output = {"0:03", "0:05", "0:06", "0:09", "0:10", "0:12", "0:17", "0:18", "0:20", "0:24", "0:33", "0:34", "0:36", "0:40", "0:48", "1:01", "1:02", "1:04", "1:08", "1:16", "1:32", "2:01", "2:02", "2:04", "2:08", "2:16", "2:32", "3:00", "4:01", "4:02", "4:04", "4:08", "4:16", "4:32", "5:00", "6:00", "8:01", "8:02", "8:04", "8:08", "8:16", "8:32", "9:00", "10:00"};
    auto temp = solution.readBinaryWatch(2);
    set<string> result(temp.begin(), temp.end());
    EXPECT_EQ(result, output);
}

TEST_F(LeetCodeTest, Case3)
{
    output = {"0:07", "0:11", "0:13", "0:14", "0:19", "0:21", "0:22", "0:25", "0:26", "0:28", "0:35", "0:37", "0:38", "0:41", "0:42", "0:44", "0:49", "0:50", "0:52", "0:56", "1:03", "1:05", "1:06", "1:09", "1:10", "1:12", "1:17", "1:18", "1:20", "1:24", "1:33", "1:34", "1:36", "1:40", "1:48", "2:03", "2:05", "2:06", "2:09", "2:10", "2:12", "2:17", "2:18", "2:20", "2:24", "2:33", "2:34", "2:36", "2:40", "2:48", "3:01", "3:02", "3:04", "3:08", "3:16", "3:32", "4:03", "4:05", "4:06", "4:09", "4:10", "4:12", "4:17", "4:18", "4:20", "4:24", "4:33", "4:34", "4:36", "4:40", "4:48", "5:01", "5:02", "5:04", "5:08", "5:16", "5:32", "6:01", "6:02", "6:04", "6:08", "6:16", "6:32", "7:00", "8:03", "8:05", "8:06", "8:09", "8:10", "8:12", "8:17", "8:18", "8:20", "8:24", "8:33", "8:34", "8:36", "8:40", "8:48", "9:01", "9:02", "9:04", "9:08", "9:16", "9:32", "10:01", "10:02", "10:04", "10:08", "10:16", "10:32", "11:00"};
    auto temp = solution.readBinaryWatch(3);
    set<string> result(temp.begin(), temp.end());
    EXPECT_EQ(result, output);
}

TEST_F(LeetCodeTest, Case8)
{
    output = {"7:31", "7:47", "7:55", "7:59", "11:31", "11:47", "11:55", "11:59"};
    auto temp = solution.readBinaryWatch(8);
    set<string> result(temp.begin(), temp.end());
    EXPECT_EQ(result, output);
}