#pragma once
#include "Common.h"

class Solution
{
public:
    int numUniqueEmails(const vector<string> &emails)
    {
        unordered_map<string, unordered_set<string>> lookup;
        for (auto &email : emails)
        {
            auto [user, domain] = parse(email);
            lookup[domain].emplace(user);
        }
        int result = 0;
        for (auto &domain : lookup)
        {
            result += domain.second.size();
        }
        return result;
    }

private:
    pair<string, string> parse(string_view email)
    {
        size_t at = email.find('@');
        string domain(email.substr(at + 1));
        string user;
        for (int i = 0; i < at; i++)
        {
            if (email[i] == '.')
                continue;

            if (email[i] == '+')
                break;

            user += email[i];
        }
        return {user, domain};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    EXPECT_EQ(solution.numUniqueEmails(emails), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> emails = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
    EXPECT_EQ(solution.numUniqueEmails(emails), 3);
}