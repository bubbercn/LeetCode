#pragma once
#include "Common.h"

class Solution
{
public:
    string customSortString(string_view order, string_view s)
    {
        unordered_map<char, int> orderMap;
        for (int i = 0; i < order.length(); i++)
        {
            orderMap[order[i]] = i;
        }
        string result(s);
        sort(result.begin(), result.end(), [&orderMap](char v1, char v2)
             {
            if (auto it1 = orderMap.find(v1), it2 = orderMap.find(v2); it1 == orderMap.end() && it2 == orderMap.end())
            {
                return v1 < v2;
            }
            else if (it1 == orderMap.end())
            {
                return false;
            }
            else if (it2 == orderMap.end())
            {
                return true;
            }
            else
            {
                return it1->second < it2->second; 
            } });
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
    EXPECT_EQ(solution.customSortString("cba", "abcd"), "cbad");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.customSortString("cbafg", "abcd"), "cbad");
}