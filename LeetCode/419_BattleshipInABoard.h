#pragma once
#include "Common.h"

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example)
{
    vector<vector<char>> board = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
    };
    EXPECT_EQ(solution.countBattleships(board), 2);
}
