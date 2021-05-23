#pragma once
#include "Common.h"

class Solution
{
public:
    int getMaxRepetitions(const string &s1, int n1, const string &s2, int n2)
    {
        if (n2 * s2.length() > n1 * s1.length())
            return 0;
        size_t index1 = 0, index2 = 0;
        int count1 = 0, count2 = 0;
        unordered_map<int, pair<int, int>> lookup;
        while (true)
        {
            if (s1[index1] == s2[index2])
            {
                index2++;
            }
            index1++;
            if (index2 == s2.length())
            {
                index2 = 0;
                count2++;
            }
            if (index1 == s1.length())
            {
                index1 = 0;
                count1++;
                if (lookup.find(index2) != lookup.end())
                {
                    break;
                }
                lookup.insert({index2, {count1, count2}});
            }
            if (count1 == n1)
                return count2 / n2;
        }
        auto [temp1, temp2] = lookup[index2];
        int result = temp2 + (n1 - temp1) / (count1 - temp1) * (count2 - temp2);
        int left1 = (n1 - temp1) % (count1 - temp1);
        count1 = 0;
        while (count1 < left1)
        {
            if (s1[index1] == s2[index2])
            {
                index2++;
            }
            index1++;
            if (index2 == s2.length())
            {
                index2 = 0;
                result++;
            }
            if (index1 == s1.length())
            {
                index1 = 0;
                count1++;
            }
        }
        return result / n2;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.getMaxRepetitions("acb", 4, "ab", 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.getMaxRepetitions("acb", 1, "acb", 1), 1);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.getMaxRepetitions("aaa", 2, "a", 2), 3);
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.getMaxRepetitions("aaab", 2, "a", 2), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.getMaxRepetitions("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                                         1000000,
                                         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                                         1000000),
              0);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.getMaxRepetitions("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                                         816807,
                                         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                                         377233),
              5);
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.getMaxRepetitions("aaa", 3, "aa", 1), 4);
}