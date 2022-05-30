#pragma once
#include "Common.h"

class Solution
{
public:
    string crackSafe(int n, int k)
    {
        string result(n, '0');
        unordered_set<int> visited = {stoi(result)};
        string cur = result;
        bool stop = false;
        while (!stop)
        {
            stop = true;
            for (int i = k - 1; i >= 0; i--)
            {
                string temp = cur.substr(1);
                temp += '0' + i;
                if (visited.emplace(stoi(temp)).second)
                {
                    result += '0' + i;
                    cur = temp;
                    stop = false;
                    break;
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
    EXPECT_EQ(solution.crackSafe(1, 2), "01");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.crackSafe(2, 2), "00110");
}
