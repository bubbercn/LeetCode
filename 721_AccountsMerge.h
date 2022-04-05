#pragma once
#include "Common.h"

class disjoint_set_union
{
public:
    disjoint_set_union(int n)
    {
        data.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            data[i] = i;
        }
    }
    int find(int input)
    {
        while (data.at(input) != input)
        {
            input = data.at(input);
        }
        return input;
    }
    int merge(int input1, int input2)
    {
        return data.at(input2) = input1;
    }
    int peek(int input)
    {
        return data.at(input);
    }
    void reset()
    {
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = i;
        }
    }

private:
    vector<int> data;
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        unordered_map<string, int> emailIDMap;
        disjoint_set_union dsu(n);
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                if (auto [it, inserted] = emailIDMap.emplace(accounts[i][j], i); !inserted)
                {
                    if (auto id = dsu.find(it->second); id != i)
                    {
                        dsu.merge(i, id);
                    }
                }
            }
        }
        unordered_map<int, string> idNameMap;
        unordered_map<int, set<string>> idEmailsMap;
        for (int i = 0; i < n; i++)
        {
            int id = dsu.find(i);
            idNameMap.emplace(id, accounts[i][0]);
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                idEmailsMap[id].emplace(accounts[i][j]);
            }
        }
        vector<vector<string>> result;
        for (auto &[id, name] : idNameMap)
        {
            vector<string> account;
            account.emplace_back(name);
            for (auto &email : idEmailsMap.at(id))
            {
                account.emplace_back(email);
            }
            result.emplace_back(account);
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
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"},
    };
    vector<vector<string>> output = {
        {"John", "johnnybravo@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
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
        {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"},
        {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
        {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
        {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
        {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},
    };
    EXPECT_EQ(solution.accountsMerge(accounts), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<string>> accounts = {
        {"David", "David0@m.co", "David1@m.co"},
        {"David", "David3@m.co", "David4@m.co"},
        {"David", "David4@m.co", "David5@m.co"},
        {"David", "David2@m.co", "David3@m.co"},
        {"David", "David1@m.co", "David2@m.co"},
    };
    vector<vector<string>> output = {
        {"David", "David0@m.co", "David1@m.co", "David2@m.co", "David3@m.co", "David4@m.co", "David5@m.co"},
    };
    EXPECT_EQ(solution.accountsMerge(accounts), output);
}
