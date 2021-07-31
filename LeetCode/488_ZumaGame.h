#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinStep(string board, string hand)
    {
        unordered_map<char, int> handByColor;
        for (auto c : hand)
        {
            handByColor[c]++;
        }
        return helper(board, handByColor);
    }

private:
    int helper(string_view board, const unordered_map<char, int> &hand)
    {
        int result = -1;
        for (int i = 0; i < board.length();)
        {
            int next = i + 1;
            if (next < board.length() && board[next] == board[i])
            {
                next++;
                for (const auto &[c, count] : hand)
                {
                    if (c == board[i] || count == 0)
                        continue;
                    unordered_map<char, int> tempHand = hand;
                    tempHand[c]--;
                    string nextBoard{board.substr(0, i + 1)};
                    nextBoard += c;
                    nextBoard += board.substr(i + 1);
                    int nextResult = helper(nextBoard, tempHand);
                    if (nextResult != -1)
                    {
                        nextResult += 1;
                        if (result == -1)
                        {
                            result = nextResult;
                        }
                        else
                        {
                            result = min(result, nextResult);
                        }
                    }
                }
            }
            unordered_map<char, int> tempHand = hand;
            if (int needCount = tryReduce(tempHand, board[i], next - i); needCount != 0)
            {
                int end = i;
                int start = next;
                while (end > 0 && start < board.length() && board[end - 1] == board[start])
                {
                    int left = 1;
                    if (end > 1 && board[end - 2] == board[end - 1])
                        left++;
                    int right = 1;
                    if (start + 1 < board.length() && board[start + 1] == board[start])
                        right++;
                    if (left + right >= 3)
                    {
                        end -= left;
                        start += right;
                    }
                    else
                    {
                        break;
                    }
                }
                int nextResult = 0;
                if (end != 0 || start != board.length())
                {
                    string nextBoard{board.substr(0, end)};
                    nextBoard += board.substr(start);
                    nextResult = helper(nextBoard, tempHand);
                }
                if (nextResult != -1)
                {
                    nextResult += needCount;
                    if (result == -1)
                    {
                        result = nextResult;
                    }
                    else
                    {
                        result = min(result, nextResult);
                    }
                }
            }
            i = next;
        }
        return result;
    }

    int tryReduce(unordered_map<char, int> &handByColor, char c, int count)
    {
        int need = 3 - count;
        if (handByColor[c] < need)
            return 0;
        handByColor[c] -= need;
        return need;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findMinStep("WRRBBW", "RB"), -1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findMinStep("WWRRBBWW", "WRBRW"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findMinStep("G", "GGGGG"), 2);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.findMinStep("RBYYBBRRB", "YRBGB"), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.findMinStep("WWGWGW", "GWBWR"), 3);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.findMinStep("RRWWRRBBRR", "WB"), 2);
}