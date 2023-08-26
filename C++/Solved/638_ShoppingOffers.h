#pragma once
#include "Common.h"

class Solution
{
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = price.size();
        filter(special, needs);
        return helper(price, special, needs);
    }

private:
    int helper(const vector<int> &price, vector<vector<int>> special, const vector<int> &needs)
    {
        if (auto it = lookup.find(needs); it != lookup.end())
        {
            return it->second;
        }

        int result = 0;
        for (int i = 0; i < needs.size(); i++)
        {
            result += price[i] * needs[i];
        }
        for (auto s : special)
        {
            auto nextNeeds = needs;
            if (!check(s, nextNeeds))
                continue;

            result = min(result, helper(price, special, nextNeeds) + *s.rbegin());
        }
        lookup[needs] = result;
        return result;
    }
    bool check(const vector<int> &special, vector<int> &needs)
    {
        for (int i = 0; i < needs.size(); i++)
        {
            needs[i] -= special[i];
            if (needs[i] < 0)
                return false;
        }
        return true;
    }
    void filter(vector<vector<int>> &special, const vector<int> &needs)
    {
        vector<vector<int>> temp;
        for (auto &s : special)
        {
            bool exclude = false;
            for (int i = 0; i < needs.size(); i++)
            {
                if (s[i] > needs[i])
                {
                    exclude = true;
                    break;
                }
            }
            if (!exclude)
                temp.emplace_back(s);
        }
        special.swap(temp);
    }
    map<vector<int>, int> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> price = {2, 5};
    vector<vector<int>> special = {
        {3, 0, 5},
        {1, 2, 10},
    };
    vector<int> needs = {3, 2};
    EXPECT_EQ(solution.shoppingOffers(price, special, needs), 14);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> price = {2, 3, 4};
    vector<vector<int>> special = {
        {1, 1, 0, 4},
        {2, 2, 1, 9},
    };
    vector<int> needs = {1, 2, 1};
    EXPECT_EQ(solution.shoppingOffers(price, special, needs), 11);
}