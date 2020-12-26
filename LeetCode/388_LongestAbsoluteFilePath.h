#pragma once
#include "Common.h"

class Solution
{
public:
    int lengthLongestPath(string input)
    {
        if (input.empty())
            return 0;
        
        size_t result = 0;
        stack<size_t> folderLengths;
        size_t curPathLength = 0;
        size_t begin = 0;
        bool isFile = false;
        size_t level = 0;
        for (string token = getNextToken(input, begin, isFile, level); !token.empty(); token = getNextToken(input, begin, isFile, level))
        {
            if (isFile)
            {
                result = max(result, curPathLength + token.length());
            }
            else
            {
                while (level != folderLengths.size())
                {
                    curPathLength -= folderLengths.top();
                    folderLengths.pop();
                }
                folderLengths.emplace(token.length() + 1);
                curPathLength += (token.length() + 1);
            }
        }

        return result;
    }

private:
    string getNextToken(const string&s, size_t& begin, bool& isFile, size_t& level)
    {
        if (begin == string::npos)
            return {};

        level = 0;
        while (begin < s.length() && s[begin] == '\t')
        {
            level++;
            begin++;
        }
        size_t end = s.find('\n', begin);
        string token = end == string::npos ? s.substr(begin) : s.substr(begin, end - begin);
        begin = end == string::npos ? string::npos : ++end;
        isFile = token.find('.') != string::npos;
        return token;
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

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.lengthLongestPath("dir\n        file.txt"), 16);
}