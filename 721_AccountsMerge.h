#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"},
    };
    vector<vector<string>> output = {
        {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"},
    };
    EXPECT_EQ(solution.accountsMerge(accounts), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<string>> accounts = {
        {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
        {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
        {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
        {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
        {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"},
    };
    vector<vector<string>> output = {
        {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
        {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},
        {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
        {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
        {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"},
    };
    EXPECT_EQ(solution.accountsMerge(accounts), output);
}