#pragma once
#include "Common.h"

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        enum class State
        {
            NOT_START,
            UP,
            DOWN,
        };
        int result = 0;
        State s = State::NOT_START;
        int begin = -1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                s = State::NOT_START;
                begin = -1;
            }
            else if (arr[i] > arr[i - 1])
            {
                if (s != State::UP)
                {
                    s = State::UP;
                    begin = i - 1;
                }
            }
            else
            {
                if (s == State::UP)
                {
                    s = State::DOWN;
                }
                if (s == State::DOWN)
                {
                    result = max(result, i - begin + 1);
                }
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
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    EXPECT_EQ(solution.longestMountain(arr), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 2, 2};
    EXPECT_EQ(solution.longestMountain(arr), 0);
}