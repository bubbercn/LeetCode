#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string_view, int> wordFrequencies;
        for (const auto &word : words)
        {
            wordFrequencies[word]++;
        }
        auto cmp = [](const pair<string_view, int> &v1, const pair<string_view, int> &v2)
        {
            if (v1.second == v2.second)
                return v1.first < v2.first;

            return v1.second > v2.second;
        };
        priority_queue<pair<string_view, int>, vector<pair<string_view, int>>, decltype(cmp)> heap(cmp);
        for (const auto &wordFrequency : wordFrequencies)
        {
            if (heap.size() < k)
            {
                heap.emplace(wordFrequency);
            }
            else if (cmp(wordFrequency, heap.top()))
            {
                heap.pop();
                heap.emplace(wordFrequency);
            }
        }
        vector<string> result(heap.size());
        for (int i = result.size() - 1; i >= 0; i--)
        {
            result[i] = heap.top().first;
            heap.pop();
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
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> output = {"i", "love"};
    EXPECT_EQ(solution.topKFrequent(words, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> output = {"the", "is", "sunny", "day"};
    EXPECT_EQ(solution.topKFrequent(words, 4), output);
}