#pragma once
#include "Common.h"

class Solution
{
public:
    int lengthLongestPath(string input)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"), 32);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.lengthLongestPath("a"), 0);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt"), 12);
}