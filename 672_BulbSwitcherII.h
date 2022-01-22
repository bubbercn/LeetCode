#pragma once
#include "Common.h"

class Solution
{
public:
    int flipLights(int n, int presses)
    {
        init(n, presses);
        int pressedButtonCount = 0;
        unordered_set<bitset<1000>> current = {buttons[0]};
        while (pressedButtonCount++ < presses)
        {
            unordered_set<bitset<1000>> next;
            for (auto& lights : current)
            {
                for (auto& button : buttons)
                {
                    next.emplace(lights ^ button);
                }
            }
            if (next == current)
                break;
            current.swap(next);
        }
        return current.size();
    }

private:
    void init(int n, int presses)
    {
        buttons.assign(4, bitset<1000>());
        for (int i = 0; i < n; i++)
        {
            buttons[0].set(i);
        }
        for (int i = 0; i < n; i += 2)
        {
            buttons[1].set(i);
        }
        for (int i = 1; i < n; i += 2)
        {
            buttons[2].set(i);
        }
        for (int i = 0; i < n; i += 3)
        {
            buttons[3].set(i);
        }
    }
    vector<bitset<1000>> buttons;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.flipLights(1, 1), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.flipLights(2, 1), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.flipLights(3, 1), 4);
}