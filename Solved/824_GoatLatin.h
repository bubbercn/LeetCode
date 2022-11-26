#pragma once
#include "Common.h"

class Solution
{
public:
    string toGoatLatin(string_view sentence)
    {
        int index = 1;
        string result;
        list<string> words = parse(sentence);
        for (auto &word : words)
        {
            if (!result.empty())
                result += ' ';
            result += transform(word, index++);
        }
        return result;
    }

private:
    list<string> parse(string_view sentence)
    {
        list<string> result;
        size_t begin = string::npos;
        for (size_t i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] != ' ')
            {
                if (begin == string::npos)
                {
                    begin = i;
                }
            }
            else
            {
                result.emplace_back(sentence.substr(begin, i - begin));
                begin = string::npos;
            }
        }
        if (begin != string::npos)
            result.emplace_back(sentence.substr(begin));
        return result;
    }
    string transform(string_view word, int index)
    {
        string result;
        if (word.find_first_not_of("aeiouAEIOU") == 0)
        {
            result = word.substr(1);
            result += word[0];
        }
        else
        {
            result = word;
        }
        result += "ma";
        result += string(index, 'a');
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
    EXPECT_EQ(solution.toGoatLatin("I speak Goat Latin"), "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.toGoatLatin("The quick brown fox jumped over the lazy dog"), "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa");
}