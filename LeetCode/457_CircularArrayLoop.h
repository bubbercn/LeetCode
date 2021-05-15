#pragma once
#include "Common.h"

class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                list<int> path;
                unordered_map<int, list<int>::const_iterator> lookup;
                int curPos = i;
                while (!visited[curPos])
                {
                    lookup.emplace(curPos, path.insert(path.end(), nums[curPos]));
                    visited[curPos] = true;
                    curPos += nums[curPos];
                    curPos %= static_cast<int>(nums.size());
                    if (curPos < 0)
                        curPos += nums.size();
                }
                if (lookup.find(curPos) == lookup.end())
                    continue;
                int length = 0;
                int first = 0;
                bool ok = true;
                for (auto j = lookup[curPos]; j != path.end(); j++)
                {
                    length++;
                    if (j == lookup[curPos])
                    {
                        first = *j;
                    }
                    else if (first * *j < 0)
                    {
                        ok = false;
                        break;
                    }
                }
                if (length > 1 && ok)
                    return true;
            }
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {2, -1, 1, 2, 2};
    EXPECT_EQ(solution.circularArrayLoop(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {-1, 2};
    EXPECT_EQ(solution.circularArrayLoop(nums), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {-2, 1, -1, -2, -2};
    EXPECT_EQ(solution.circularArrayLoop(nums), false);
}
