#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
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
    vector<string> cpdomains = {"9001 discuss.leetcode.com"};
    vector<string> output = {"9001 leetcode.com", "9001 discuss.leetcode.com", "9001 com"};
    EXPECT_EQ(solution.subdomainVisits(cpdomains), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> output = {"901 mail.com", "50 yahoo.com", "900 google.mail.com", "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"};
    EXPECT_EQ(solution.subdomainVisits(cpdomains), output);
}
