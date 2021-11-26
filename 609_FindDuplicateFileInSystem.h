#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
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
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> output = {
        {"root/a/2.txt", "root/c/d/4.txt", "root/4.txt"},
        {"root/a/1.txt", "root/c/3.txt"},
    };
    EXPECT_EQ(solution.findDuplicate(paths), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)"};
    vector<vector<string>> output = {
        {"root/a/2.txt", "root/c/d/4.txt"},
        {"root/a/1.txt", "root/c/3.txt"},
    };
    EXPECT_EQ(solution.findDuplicate(paths), output);
}