#pragma once
#include "Common.h"

class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long num = 0;
        try
        {
            num = stol(n);
        }
        catch (const exception &)
        {
            return {};
        }

        vector<long> primeFactors = getPrimeFactors(num - 1);
        set<long> factors = getAllFactors(primeFactors);
        for (auto factor : factors)
        {
            if (factor == 1)
                continue;
            if (validate(factor, num))
                return to_string(factor);
        }
        return {};
    }

private:
    vector<long> getPrimeFactors(long n)
    {
        vector<long> result;
        while (true)
        {
            bool foundPrimeFactor = false;
            for (long i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    result.emplace_back(i);
                    n /= i;
                    foundPrimeFactor = true;
                    break;
                }
            }
            if (!foundPrimeFactor)
            {
                result.emplace_back(n);
                break;
            }
        }
        return result;
    }

    set<long> getAllFactors(vector<long>& primeFactors)
    {
        if (primeFactors.size() == 0)
            return {1};

        long last = *primeFactors.rbegin();
        primeFactors.resize(primeFactors.size() - 1);
        set<long> temp = getAllFactors(primeFactors);
        set<long> result = temp;
        for (auto num : temp)
        {
            result.emplace(num * last);
        }
        return result;
    }

    bool validate(long factor, long num)
    {
        while (--num > 0)
        {
            if (num % factor != 0)
                return false;
            num /= factor;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.smallestGoodBase("13"), "3");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.smallestGoodBase("4681"), "8");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.smallestGoodBase("1000000000000000000"), "999999999999999999");
}