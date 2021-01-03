#pragma once
#include "Common.h"

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<pair<string, string>, double> edgeLookup;
        set<string> vertexLookup;
        for (int i = 0; i < equations.size(); i++)
        {
            vertexLookup.emplace(equations[i][0]);
            vertexLookup.emplace(equations[i][1]);
            edgeLookup.emplace(make_pair(equations[i][0], equations[i][0]), 1.0);
            edgeLookup.emplace(make_pair(equations[i][1], equations[i][1]), 1.0);
            edgeLookup.emplace(make_pair(equations[i][0], equations[i][1]), values[i]);
            edgeLookup.emplace(make_pair(equations[i][1], equations[i][0]), 1.0 / values[i]);
        }

        for (auto& k : vertexLookup)
        {
            for (auto& i : vertexLookup)
            {
                for (auto& j : vertexLookup)
                {
                    auto it = edgeLookup.find(make_pair(i, j));
                    if (it != edgeLookup.end())
                        continue;
                    double value = 0;
                    it = edgeLookup.find(make_pair(i, k));
                    if (it == edgeLookup.end())
                        continue;
                    value = it->second;
                    it = edgeLookup.find(make_pair(k, j));
                    if (it == edgeLookup.end())
                        continue;
                    value *= it->second;
                    edgeLookup.emplace(make_pair(i, j), value);
                    edgeLookup.emplace(make_pair(j, i), 1.0 / value);
                }
            }
        }

        vector<double> result(queries.size(), 0.0);
        for (int i = 0; i < queries.size(); i++)
        {
            if (auto it = edgeLookup.find(make_pair(queries[i][0], queries[i][1])); it != edgeLookup.end())
            {
                result[i] = it->second;
            }
            else
            {
                result[i] = -1.0;
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<vector<string>> equations;
    inline static vector<double> values;
    inline static vector<vector<string>> queries;
    inline static vector<double> output;
};

TEST_F(LeetCodeTest, Example1)
{
    equations = {
        {"a", "b"},
        {"b", "c"},
    };
    values = {2.0, 3.0};
    queries = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"},
    };
    output = {6.0, 0.5, -1.0, 1.0, -1.0};
    EXPECT_EQ(solution.calcEquation(equations, values, queries), output);
}

TEST_F(LeetCodeTest, Example2)
{
    equations = {
        {"a", "b"},
        {"b", "c"},
        {"bc", "cd"},
    };
    values = {1.5, 2.5, 5.0};
    queries = {
        {"a", "c"},
        {"c", "b"},
        {"bc", "cd"},
        {"cd", "bc"},
    };
    output = {3.75000, 0.40000, 5.00000, 0.20000};
    EXPECT_EQ(solution.calcEquation(equations, values, queries), output);
}

TEST_F(LeetCodeTest, Example3)
{
    equations = {
        {"a", "b"},
    };
    values = {0.5};
    queries = {
        {"a", "b"},
        {"b", "a"},
        {"a", "c"},
        {"x", "y"},
    };
    output = {0.50000, 2.00000, -1.00000, -1.00000};
    EXPECT_EQ(solution.calcEquation(equations, values, queries), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    equations = {
        {"a", "e"},
        {"b", "e"},
    };
    values = {4.0, 3.0};
    queries = {
        {"a", "b"},
        {"e", "e"},
        {"x", "x"},
    };
    output = {4.0 / 3.0, 1.00000, -1.00000};
    EXPECT_EQ(solution.calcEquation(equations, values, queries), output);
}
