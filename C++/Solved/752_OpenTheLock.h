#pragma once
#include "Common.h"

class Solution
{
public:
    int openLock(vector<string> &deadends, const string& target)
    {
        string start = "0000";
        if (start == target)
            return 0;

        int result = 1;
        list<string> current;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count(start) == 0)
        {
            current.emplace_back(start);
            visited.emplace(start);
        }
        while (!current.empty())
        {
            list<string> next;
            for (auto& s : current)
            {
                for (int i = 0; i < 4; i++)
                {
                    string temp = s;
                    if (temp[i] == '9')
                    {
                        temp[i] = '0';
                    }
                    else
                    {
                        temp[i]++;
                    }
                    if (temp == target)
                        return result;
                    
                    if (visited.count(temp) == 0)
                    {
                        next.emplace_back(temp);
                        visited.emplace(temp);
                    }

                    temp = s;
                    if (temp[i] == '0')
                    {
                        temp[i] = '9';
                    }
                    else
                    {
                        temp[i]--;
                    }
                    if (temp == target)
                        return result;
                    
                    if (visited.count(temp) == 0)
                    {
                        next.emplace_back(temp);
                        visited.emplace(temp);
                    }
                }
            }
            current.swap(next);
            result++;
        }
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    EXPECT_EQ(solution.openLock(deadends, "0202"), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> deadends = {"8888"};
    EXPECT_EQ(solution.openLock(deadends, "0009"), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    EXPECT_EQ(solution.openLock(deadends, "8888"), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> deadends = {"0000"};
    EXPECT_EQ(solution.openLock(deadends, "8888"), -1);
}