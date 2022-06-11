#pragma once
#include "Common.h"

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if (auto it = upper_bound(letters.begin(), letters.end(), target); it == letters.end())
        {
            return *letters.begin();
        }      
        else
        {
            return *it;
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
    vector<char> letters = {'c', 'f', 'j'};
    EXPECT_EQ(solution.nextGreatestLetter(letters, 'a'), 'c');
}

TEST_F(LeetCodeTest, Example2)
{
    vector<char> letters = {'c', 'f', 'j'};
    EXPECT_EQ(solution.nextGreatestLetter(letters, 'c'), 'f');
}

TEST_F(LeetCodeTest, Example3)
{
    vector<char> letters = {'c', 'f', 'j'};
    EXPECT_EQ(solution.nextGreatestLetter(letters, 'd'), 'f');
}