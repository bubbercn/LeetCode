#pragma once
#include "Common.h"

class TopVotedCandidate
{
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        multimap<int, int> state;
        unordered_map<int, multimap<int, int>::const_iterator> lookup;
        int n = persons.size();
        for (int i = 0; i < n; i++)
        {
            int time = times[i];
            int person = persons[i];
            int votes = 0;
            if (auto it = lookup.find(person); it != lookup.end())
            {
                votes = it->second->first;
                state.erase(it->second);
                lookup.erase(it);
            }
            votes++;
            lookup.emplace(person, state.emplace(votes, person));
            winner.emplace(time, state.rbegin()->second);
        }
    }

    int q(int t)
    {
        return (--winner.upper_bound(t))->second;
    }

private:
    map<int, int> winner;
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