#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> lookup;
        for (auto& cpdomain : cpdomains)
        {
            int count = 0;
            int begin = 0, end = 0;
            end = cpdomain.find(' ');
            count = stoi(cpdomain.substr(0, end));
            do
            {
                begin = end + 1;
                lookup[cpdomain.substr(begin)] += count;
                end = cpdomain.find('.', begin);
            } while (end != string::npos);
        }
        vector<string> result;
        for (auto& [s, c] : lookup)
        {
            string temp = to_string(c) + ' ' + s;
            result.emplace_back(temp);
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
