#pragma once
#include "Common.h"

class Solution
{
public:
    int strongPasswordChecker(string password)
    {
        int result = 0;
        int length = password.length();
        bool hasLowerCase = false;
        bool hasUpperCase = false;
        bool hasDigit = false;
        int missingCount = 0;
        int repeatCount = 0;
        vector<list<int>> repeatCounts(3);
        for (int i = 0; i < password.length(); i++)
        {
            if (!hasLowerCase && password[i] >= 'a' && password[i] <= 'z')
            {
                hasLowerCase = true;
            }
            if (!hasUpperCase && password[i] >= 'A' && password[i] <= 'Z')
            {
                hasUpperCase = true;
            }
            if (!hasDigit && password[i] >= '0' && password[i] <= '9')
            {
                hasDigit = true;
            }
            if (i == 0 || password[i] == password[i - 1])
            {
                repeatCount++;
            }
            else
            {
                if (repeatCount >= 3)
                {
                    repeatCounts[repeatCount % 3].emplace_back(repeatCount);
                }
                repeatCount = 1;
            }
        }

        if (repeatCount >= 3)
        {
            repeatCounts[repeatCount % 3].emplace_back(repeatCount);
        }

        if (!hasLowerCase)
        {
            missingCount++;
        }
        if (!hasUpperCase)
        {
            missingCount++;
        }
        if (!hasDigit)
        {
            missingCount++;
        }

        if (length < 6)
        {
            result = max(missingCount, 6 - length);
        }
        else if (length <= 20)
        {
            for (auto &i : repeatCounts)
            {
                for (auto j : i)
                {
                    result += (j / 3);
                }
            }
            result = max(missingCount, result);
        }
        else
        {
            int toRemove = length - 20;

            while (true)
            {
                int temp1 = toRemove;
                for (int i = 0; i < 3; i++)
                {
                    for (auto j = repeatCounts[i].begin(); j != repeatCounts[i].end() && toRemove > 0;)
                    {
                        int temp3 = min(toRemove, i + 1);
                        (*j) -= temp3;
                        toRemove -= temp3;
                        int temp2 = *j;
                        j = repeatCounts[i].erase(j);
                        if (temp2 >= 3)
                        {
                            repeatCounts[(i + 2) % 3].emplace_back(temp2);
                        }
                    }
                }
                if (temp1 == toRemove)
                    break;
            }

            for (int i = 0; i < missingCount; i++)
            {
                if (!repeatCounts[2].empty())
                {
                    repeatCounts[2].back() -= 3;
                    if (repeatCounts[2].back() < 3)
                    {
                        repeatCounts[2].pop_back();
                    }
                }
                else if (!repeatCounts[1].empty())
                {
                    repeatCounts[1].back() -= 3;
                    if (repeatCounts[1].back() < 3)
                    {
                        repeatCounts[1].pop_back();
                    }
                }
                else if (!repeatCounts[0].empty())
                {
                    repeatCounts[0].back() -= 3;
                    if (repeatCounts[0].back() < 3)
                    {
                        repeatCounts[0].pop_back();
                    }
                }
            }

            for (auto &i : repeatCounts)
            {
                for (auto j : i)
                {
                    result += (j / 3);
                }
            }
            result += (missingCount + length - 20);
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
    EXPECT_EQ(solution.strongPasswordChecker("a"), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.strongPasswordChecker("aA1"), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.strongPasswordChecker("1337C0d3"), 0);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.strongPasswordChecker("aaaaaaaaaaaaaaaaaaaa"), 6);
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.strongPasswordChecker("aaaaaaaaaaaaaaaaaaaabbb"), 9);
}

TEST_F(LeetCodeTest, Case3)
{
    EXPECT_EQ(solution.strongPasswordChecker("aaaabbbbccccddddeeeeffff"), 8);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.strongPasswordChecker("ABABABABABABABABABAB1"), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc"), 8);
}