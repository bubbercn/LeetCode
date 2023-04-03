#pragma once
#include "Common.h"

class TopVotedCandidate
{
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
    }

    int q(int t)
    {
        return 0;
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times = {0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate topVotedCandidate(persons, times);
    EXPECT_EQ(topVotedCandidate.q(3), 0);  // return 0, At time 3, the votes are [0], and 0 is leading.
    EXPECT_EQ(topVotedCandidate.q(12), 1); // return 1, At time 12, the votes are [0,1,1], and 1 is leading.
    EXPECT_EQ(topVotedCandidate.q(25), 1); // return 1, At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
    EXPECT_EQ(topVotedCandidate.q(15), 0); // return 0
    EXPECT_EQ(topVotedCandidate.q(24), 0); // return 0
    EXPECT_EQ(topVotedCandidate.q(8), 1);  // return 1
}