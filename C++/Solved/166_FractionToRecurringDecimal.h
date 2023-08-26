#pragma once
#include "Common.h"

struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution 
{
public:
    string fractionToDecimal(int x, int y) 
    {
        long long numerator = x;
        long long denominator = y;
        string result;
        char buff[128];
        if (denominator < 0)
        {
            denominator = - denominator;
            numerator = - numerator;
        }

        if (numerator < 0)
        {
            result += "-";
            numerator = - numerator;
        }
        long long quotient = numerator / denominator;
        sprintf(buff,"%lld", quotient);
        result += buff;
        int remainder = numerator % denominator;
        result += helper(remainder, denominator);
        return result;
    }
private:
    string helper(long long remainder, long long denominator)
    {
        if (remainder == 0)
            return {};
        
        list<int> digits;
        unordered_map<pair<int, int>, list<int>::iterator, pair_hash> remainderLookup;
        list<int>::iterator begin = digits.end();
        while (remainder != 0)
        {
            long long numerator = remainder * 10;
            remainder = numerator % denominator;
            int quotient = numerator / denominator;

            auto it = remainderLookup.find(make_pair(quotient, remainder));
            if (it != remainderLookup.end())
            {
                begin = it->second;
                break;
            }

            digits.emplace_back(quotient);
            remainderLookup.emplace(make_pair(quotient, remainder), --digits.end());
        }
        string result = ".";
        result.reserve(128);
        bool needEnd = false;
        for (auto it = digits.begin(); it != digits.end(); it++)
        {
            if (it == begin)
            {
                result += '(';
                needEnd = true;
            }
            result += (*it - 0 + '0');
        }
        if (needEnd)
        {
            result += ')';
        }
        return result;
    }
};

void Test()
{
    Solution solution;

    assert(solution.fractionToDecimal(1, 2) == "0.5");
    assert(solution.fractionToDecimal(2, 1) == "2");
    assert(solution.fractionToDecimal(-2, 1) == "-2");
    assert(solution.fractionToDecimal(2, 3) == "0.(6)");
    assert(solution.fractionToDecimal(-3, 2) == "-1.5");
    assert(solution.fractionToDecimal(-4, 333) == "-0.(012)");
    assert(solution.fractionToDecimal(-1, 6) == "0.1(6)");
    assert(solution.fractionToDecimal(7, -12) == "-0.58(3)");
    assert(solution.fractionToDecimal(-1, -2147483648) == "0.0000000004656612873077392578125");
    assert(solution.fractionToDecimal(-2147483648, 1) == "-2147483648");
}
