#pragma once
#include "Common.h"

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string_view sentence)
    {
        sort(dictionary.begin(), dictionary.end(), [](const string &s1, const string &s2)
             { return s1.length() < s2.length(); });
        string result;
        int i = 1;
        int begin = 0;
        while (i < sentence.length())
        {
            if (sentence[i] == ' ')
            {
                string_view word = sentence.substr(begin, i - begin);
                result += findRoot(dictionary, word);
                result += ' ';
                begin = i + 1;
            }
            i++;
        }
        string_view word = sentence.substr(begin, i - begin);
        result += findRoot(dictionary, word);
        return result;
    }

private:
    string findRoot(const vector<string> &dictionary, string_view word)
    {
        string result;
        for (auto &root : dictionary)
        {
            if (root.length() > word.length())
                break;

            if (root == string(word.begin(), root.length()))
            {
                return root;
            }
        }
        return string(word.begin(), word.length());
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> dictionary = {"cat", "bat", "rat"};
    EXPECT_EQ(solution.replaceWords(dictionary, "the cattle was rattled by the battery"), "the cat was rat by the bat");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> dictionary = {"a", "b", "c"};
    EXPECT_EQ(solution.replaceWords(dictionary, "aadsfasf absbs bbab cadsfafs"), "a a b c");
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> dictionary = {"a", "aa", "aaa", "aaaa"};
    EXPECT_EQ(solution.replaceWords(dictionary, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"), "a a a a a a a a bbb baba a");
}
