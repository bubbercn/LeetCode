#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> result;
        bool inComment = false;
        string lineNoComment;
        for (auto &line : source)
        {
            size_t curPos = 0;
            while (true)
            {
                if (inComment)
                {
                    if (auto pos = line.find("*/", curPos); pos == string::npos)
                    {
                        break;
                    }
                    else
                    {
                        inComment = false;
                        curPos = pos + 2;
                    }
                }
                else
                {
                    if (auto pos = line.find('/', curPos); pos != string::npos)
                    {
                        if (pos + 1 < line.length())
                        {
                            if (line[pos + 1] == '/')
                            {
                                lineNoComment += line.substr(curPos, pos - curPos);
                                if (!lineNoComment.empty())
                                {
                                    result.emplace_back(lineNoComment);
                                }
                                lineNoComment.clear();
                                break;
                            }
                            else if (line[pos + 1] == '*')
                            {
                                lineNoComment += line.substr(curPos, pos - curPos);
                                curPos = pos + 2;
                                inComment = true;
                            }
                            else
                            {
                                lineNoComment += line.substr(curPos, pos + 2 - curPos);
                                curPos = pos + 2;
                            }
                        }
                        else
                        {
                            lineNoComment += line.substr(curPos);
                            if (!lineNoComment.empty())
                            {
                                result.emplace_back(lineNoComment);
                            }
                            lineNoComment.clear();
                            break;
                        }
                    }
                    else
                    {
                        lineNoComment += line.substr(curPos);
                        if (!lineNoComment.empty())
                        {
                            result.emplace_back(lineNoComment);
                        }
                        lineNoComment.clear();
                        break;
                    }
                }
            }
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
    vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    vector<string> output = {"int main()", "{ ", "  ", "int a, b, c;", "a = b + c;", "}"};
    EXPECT_EQ(solution.removeComments(source), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> source = {"a/*comment", "line", "more_comment*/b"};
    vector<string> output = {"ab"};
    EXPECT_EQ(solution.removeComments(source), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> source = {"a//*b//*c", "blank", "d/*/e*//f"};
    vector<string> output = {"a", "blank", "d/f"};
    EXPECT_EQ(solution.removeComments(source), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<string> source = {"void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"};
    vector<string> output = {"void func(int k) {", "   k = k*2/4;", "   k = k/2;*/", "}"};
    EXPECT_EQ(solution.removeComments(source), output);
}