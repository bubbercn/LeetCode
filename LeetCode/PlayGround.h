#pragma once
#include "Common.h"

class Solution
{
public:
    int maxNiceDivisors(int primeFactors)
    {
        if (primeFactors == 1)
            return 1;
        
        long result = 0;

        switch (primeFactors % 3)
        {
        case 0:
            result = helper(primeFactors/3);
            break;
        case 1:
            result = 4 * helper((primeFactors-4)/3);
            break;
        default:
            result = 2 * helper(primeFactors/3);
            break;
        }

        return result % threshold;
    }

private:
    long helper(int n)
    {
        if (n == 0)
            return 1;
        long temp = helper(n/2);
        if (n %2 == 0)
        {
            return temp * temp % threshold;
        }
        else
        {
            return 3 * temp * temp % threshold;
        }
    }
    inline constexpr static int threshold = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.maxNiceDivisors(1), 1);
    EXPECT_EQ(solution.maxNiceDivisors(2), 2);
    EXPECT_EQ(solution.maxNiceDivisors(3), 3);
    EXPECT_EQ(solution.maxNiceDivisors(4), 4);
    EXPECT_EQ(solution.maxNiceDivisors(5), 6);
    EXPECT_EQ(solution.maxNiceDivisors(6), 9);
    EXPECT_EQ(solution.maxNiceDivisors(7), 12);
    EXPECT_EQ(solution.maxNiceDivisors(8), 18);
    EXPECT_EQ(solution.maxNiceDivisors(100), 703522804);
    EXPECT_EQ(solution.maxNiceDivisors(901891104), 713696372);
}

// TEST_F(LeetCodeTest, Example2)
// {
//     EXPECT_EQ(solution.maxValue(6, 1, 10), 3);
// }

// TEST_F(LeetCodeTest, Example3)
// {
//     EXPECT_EQ(solution.areAlmostEqual("kelb", "kelb"), true);
// }

// TEST_F(LeetCodeTest, Example4)
// {
//     EXPECT_EQ(solution.areAlmostEqual("abcd", "dcba"), false);
// }

// TEST_F(LeetCodeTest, Faulre1)
// {
//     EXPECT_EQ(solution.maxValue(3, 2, 18), 7);
// }

// TEST_F(LeetCodeTest, Faulre2)
// {
//     EXPECT_EQ(solution.maxValue(4458197, 897057, 683214517), 26053);
// }