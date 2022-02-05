#pragma once
#include "Common.h"

class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
    {
        generateOpCombinations();
        vector<vector<int>> cardCombinations = generateCardCombinations(cards);
        return search(cardCombinations);
    }

private:
    vector<vector<int>> generateCardCombinations(const vector<int> &cards)
    {
        if (cards.size() == 1)
            return {{cards[0]}};

        vector<vector<int>> result;
        for (int i = 0; i < cards.size(); i++)
        {
            vector<int> temp = cards;
            temp.erase(temp.begin() + i);
            vector<vector<int>> combinations = generateCardCombinations(temp);
            for (auto &combination : combinations)
            {
                combination.emplace_back(cards[i]);
                result.emplace_back(combination);
            }
        }
        return result;
    }
    bool search(vector<vector<int>> &cardCombinations)
    {
        for (auto &cardCombination : cardCombinations)
        {
            for (auto &opCombination : opCombinations)
            {
                if (searchOne(cardCombination, opCombination))
                    return true;
            }
        }
        return false;
    }
    bool searchOne(vector<int> cardCombination, vector<char> opCombination)
    {
        try
        {
            if (check(calc1(cardCombination, opCombination)))
                return true;
            if (check(calc2(cardCombination, opCombination)))
                return true;
            if (check(calc3(cardCombination, opCombination)))
                return true;
            if (check(calc4(cardCombination, opCombination)))
                return true;
            if (check(calc5(cardCombination, opCombination)))
                return true;
        }
        catch (const std::exception &e)
        {
            return false;
        }
        return false;
    }
    bool check(float v1)
    {
        return abs(v1 - 24.0) < 0.00001;
    }
    float calc1(vector<int> cardCombination, vector<char> opCombination)
    {
        float v1 = calc(cardCombination[0], cardCombination[1], opCombination[0]);
        float v2 = calc(cardCombination[2], cardCombination[3], opCombination[2]);
        return calc(v1, v2, opCombination[1]);
    }
    float calc2(vector<int> cardCombination, vector<char> opCombination)
    {
        float v = calc(cardCombination[0], cardCombination[1], opCombination[0]);
        v = calc(v, cardCombination[2], opCombination[1]);
        return calc(v, cardCombination[3], opCombination[2]);
    }
    float calc3(vector<int> cardCombination, vector<char> opCombination)
    {
        float v = calc(cardCombination[2], cardCombination[3], opCombination[2]);
        v = calc(cardCombination[1], v, opCombination[1]);
        return calc(cardCombination[0], v, opCombination[0]);
    }
    float calc4(vector<int> cardCombination, vector<char> opCombination)
    {
        float v = calc(cardCombination[1], cardCombination[2], opCombination[1]);
        v = calc(cardCombination[0], v, opCombination[0]);
        return calc(v, cardCombination[3], opCombination[2]);
    }
    float calc5(vector<int> cardCombination, vector<char> opCombination)
    {
        float v = calc(cardCombination[1], cardCombination[2], opCombination[1]);
        v = calc(v, cardCombination[3], opCombination[2]);
        return calc(cardCombination[0], v, opCombination[0]);
    }
    float calc(float v1, float v2, char op)
    {
        switch (op)
        {
        case '+':
            return v1 + v2;
            break;
        case '-':
            return v1 - v2;
            break;
        case '*':
            return v1 * v2;
            break;
        case '/':
            if (v2 == 0)
                throw exception();
            return v1 / v2;
        default:
            break;
        }
        assert(false);
        return 0;
    }
    inline static vector<vector<char>> opCombinations;
    static void generateOpCombinations()
    {
        if (!opCombinations.empty())
            return;

        vector<char> ops = {'+', '-', '*', '/'};
        for (int i = 0; i < ops.size(); i++)
        {
            opCombinations.push_back({ops[i]});
        }

        for (int i = 1; i < 3; i++)
        {
            vector<vector<char>> temp;
            for (const auto &combination : opCombinations)
            {
                for (int j = 0; j < ops.size(); j++)
                {
                    temp.emplace_back(combination);
                    temp.rbegin()->emplace_back(ops[j]);
                }
            }
            opCombinations.swap(temp);
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> cards = {4, 1, 8, 7};
    EXPECT_EQ(solution.judgePoint24(cards), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> cards = {1, 2, 1, 2};
    EXPECT_EQ(solution.judgePoint24(cards), false);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> cards = {1, 2, 1, 0};
    EXPECT_EQ(solution.judgePoint24(cards), false);
}

TEST_F(LeetCodeTest, Case2)
{
    vector<int> cards = {8, 2, 1, 3};
    EXPECT_EQ(solution.judgePoint24(cards), true);
}

TEST_F(LeetCodeTest, Case3)
{
    vector<int> cards = {8, 8, 3, 3};
    EXPECT_EQ(solution.judgePoint24(cards), true);
}

TEST_F(LeetCodeTest, Case4)
{
    vector<int> cards = {5, 5, 5, 1};
    EXPECT_EQ(solution.judgePoint24(cards), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> cards = {1, 5, 9, 1};
    EXPECT_EQ(solution.judgePoint24(cards), false);
}