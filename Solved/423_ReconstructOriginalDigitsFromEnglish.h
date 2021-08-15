#pragma once
#include "Common.h"

class Solution
{
public:
    string originalDigits(string s)
    {
        stringstream temp;
        vector<int> lookup(26, 0);
        for (auto c : s)
        {
            lookup.at(c - 'a')++;
        }

        auto process = [&temp, &lookup](char key, const string &num) {
            int count = lookup.at(key - 'a');
            for (int i = 0; i < count; i++)
            {
                temp << string2DigitMap.at(num);
            }
            for (auto c : num)
            {
                lookup.at(c - 'a') -= count;
            }
        };

        process('z', "zero");
        process('w', "two");
        process('u', "four");
        process('g', "eight");
        process('x', "six");
        process('f', "five");
        process('v', "seven");
        process('o', "one");
        process('t', "three");
        process('i', "nine");

        string result = temp.str();
        sort(result.begin(), result.end());
        return result;
    }

private:
    inline static unordered_map<string, char> string2DigitMap = {
        {"zero", '0'},
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'},
    };
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.originalDigits("owoztneoer"), "012");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.originalDigits("fviefuro"), "45");
}