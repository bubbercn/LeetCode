#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> scoreCopy = score;
        sort(scoreCopy.begin(), scoreCopy.end(), greater<int>());
        unordered_map<int, int> score2Rank;
        for (int i = 0; i < scoreCopy.size(); i++)
        {
            score2Rank.emplace(scoreCopy[i], i + 1);
        }
        vector<string> result;
        result.reserve(score.size());
        for (auto s : score)
        {
            result.emplace_back(getRank(score2Rank[s]));
        }
        return result;
    }

private:
    string getRank(int rank)
    {
        if (rank == 1)
        {
            return "Gold Medal";
        }
        else if (rank == 2)
        {
            return "Silver Medal";
        }
        else if (rank == 3)
        {
            return "Bronze Medal";
        }
        else
        {
            return to_string(rank);
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> output = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    EXPECT_EQ(solution.findRelativeRanks(score), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> output = {"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"};
    EXPECT_EQ(solution.findRelativeRanks(score), output);
}