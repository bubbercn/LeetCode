#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> lookup;
        int min = numeric_limits<int>::max();
        vector<string> result;
        for (int i = 0; i < list1.size(); i++)
        {
            lookup.emplace(list1[i], i);
        }
        for (int i = 0; i < list2.size(); i++)
        {
            if (auto it = lookup.find(list2[i]); it != lookup.end())
            {
                int score = it->second + i;

                if (score > min)
                    continue;

                if (score < min)
                {
                    min = score;
                    result.clear();
                }
                result.emplace_back(list2[i]);
            }
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
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> output = {"Shogun"};
    EXPECT_EQ(solution.findRestaurant(list1, list2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    vector<string> output = {"Shogun"};
    EXPECT_EQ(solution.findRestaurant(list1, list2), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
    vector<string> output = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
    EXPECT_EQ(solution.findRestaurant(list1, list2), output);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KNN", "KFC", "Burger King", "Tapioca Express", "Shogun"};
    vector<string> output = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
    EXPECT_EQ(solution.findRestaurant(list1, list2), output);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<string> list1 = {"KFC"};
    vector<string> list2 = {"KFC"};
    vector<string> output = {"KFC"};
    EXPECT_EQ(solution.findRestaurant(list1, list2), output);
}