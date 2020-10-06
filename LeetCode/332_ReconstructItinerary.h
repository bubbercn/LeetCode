#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> ticketsMap;
        for (auto &ticket : tickets)
        {
            ticketsMap[ticket[0]].emplace(ticket[1]);
        }
        vector<string> path(tickets.size() + 1);
        path[0] = "JFK";
        int length = 1;
        string from = "JFK";
        while (length != path.size())
        {
            multiset<string>::const_iterator to;
            auto it = ticketsMap.find(from);
            if (it == ticketsMap.end() || (*it).second.empty())
            {
                do
                {
                    length--;
                    from = path[length - 1];
                    ticketsMap[from].emplace(path[length]);
                    to = ticketsMap[from].upper_bound(path[length]);
                } while (to == ticketsMap[from].end());
            }
            else
            {
                to = ticketsMap[from].begin();
            }
            path[length++] = *to;
            ticketsMap[from].erase(to);
            from = path[length - 1];
        }
        return path;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<string>> input = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> output = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    EXPECT_EQ(solution.findItinerary(input), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<string>> input = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> output = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    EXPECT_EQ(solution.findItinerary(input), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<string>> input = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    vector<string> output = {"JFK", "NRT", "JFK", "KUL"};
    EXPECT_EQ(solution.findItinerary(input), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<string>> input = {{"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"}};
    vector<string> output = {"JFK", "ANU", "EZE", "AXA", "TIA", "ANU", "JFK", "TIA", "ANU", "TIA", "JFK"};
    EXPECT_EQ(solution.findItinerary(input), output);
}
