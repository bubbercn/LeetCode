#pragma once
#include "Common.h"

class Solution
{
public:
    string countOfAtoms(const string &formula)
    {
        auto tokenList = tokenize(formula);
        stack<list<pair<string, int>>::iterator> lefts;
        for (auto i = tokenList.begin(); i != tokenList.end();)
        {
            if (i->first == "(")
            {
                lefts.emplace(i++);
            }
            else if (i->first == ")")
            {
                for (auto j = tokenList.erase(lefts.top()); j != i; j++)
                {
                    j->second *= i->second;
                }
                i = tokenList.erase(i);
                lefts.pop();
            }
            else
            {
                i++;
            }
        }
        map<string, int> atomCountMap;
        for (auto &[atom, count] : tokenList)
        {
            atomCountMap[atom] += count;
        }
        string result;
        for (auto &[atom, count] : atomCountMap)
        {
            result += atom;
            if (count != 1)
                result += to_string(count);
        }
        return result;
    }

private:
    list<pair<string, int>> tokenize(const string &formula)
    {
        list<pair<string, int>> result;
        pair<string, int> token;
        string count;
        for (auto c : formula)
        {
            if (c == '(' || c == ')' || (c >= 'A' && c <= 'Z'))
            {
                if (!token.first.empty())
                {
                    if (!count.empty())
                    {
                        token.second = stoi(count);
                        count.clear();
                    }
                    result.emplace_back(token);
                }
                token.first = c;
                token.second = 1;
            }
            else if (c >= 'a' && c <= 'z')
            {
                token.first += c;
            }
            else
            {
                count += c;
            }
        }
        if (!token.first.empty())
        {
            if (!count.empty())
            {
                token.second = stoi(count);
                count.clear();
            }
            result.emplace_back(token);
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
    EXPECT_EQ(solution.countOfAtoms("H2O"), "H2O");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countOfAtoms("Mg(OH)2"), "H2MgO2");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.countOfAtoms("K4(ON(SO3)2)2"), "K4N2O14S4");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.countOfAtoms("Nd37At28In40Si48Ti38Ds37Sm(Ho26No38)7(Tm35)24Li14Mo34(Nb7Te45Bk35Sr27Yb11Yb18Rn31)10(Po8)30(Ra)27As7Ir38Mt46BaTi37Np43Sm19Mo46Hs37Ga44ZrAu7Pb44Ca48PaNa15Ds4Ac9(Co2Cd39)5(Lv5Ga36No31Si8)16"), "Ac9As7At28Au7BaBk350Ca48Cd195Co10Ds41Ga620Ho182Hs37In40Ir38Li14Lv80Mo80Mt46Na15Nb70Nd37No762Np43PaPb44Po240Ra27Rn310Si176Sm20Sr270Te450Ti75Tm840Yb290Zr");
}