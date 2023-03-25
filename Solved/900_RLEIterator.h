#pragma once
#include "Common.h"

class RLEIterator
{
public:
    RLEIterator(vector<int> &encoding)
    {
        long total = 0;
        for (int i = 0; i < encoding.size(); i+=2)
        {
            if (encoding[i] == 0)
                continue;

            total += encoding[i];
            if (i == 0 || encoding[i + 1] != encoding[i - 1])
            {
                numbers.emplace_back(encoding[i + 1]);
                countSum.emplace_back(total);
            }
            else
            {
                countSum.back() = total;
            }
        }
    }

    int next(int n)
    {
        if (auto it = lower_bound(countSum.begin(), countSum.end(), n); it == countSum.end())
        {
            numbers.clear();
            countSum.clear();
            return -1;
        }
        else
        {
            int d = distance(countSum.begin(), it);
            int result = *(numbers.begin() + d);
            numbers.erase(numbers.begin(), numbers.begin() + d);
            auto begin = countSum.erase(countSum.begin(), countSum.begin() + d);
            for (auto i = begin; i != countSum.end(); i++)
            {
                *i -= n;
            }
            return result;
        }
    }

    deque<int> numbers;
    deque<long> countSum;    
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> encoding = {3, 8, 0, 9, 2, 5};
    RLEIterator rLEIterator(encoding);  // This maps to the sequence [8,8,8,5,5].
    EXPECT_EQ(rLEIterator.next(2), 8);  // exhausts 2 terms of the sequence, returning 8. The remaining sequence is now [8, 5, 5].
    EXPECT_EQ(rLEIterator.next(1), 8);  // exhausts 1 term of the sequence, returning 8. The remaining sequence is now [5, 5].
    EXPECT_EQ(rLEIterator.next(1), 5);  // exhausts 1 term of the sequence, returning 5. The remaining sequence is now [5].
    EXPECT_EQ(rLEIterator.next(2), -1); // exhausts 2 terms, returning -1. This is because the first term exhausted was 5, but the second term did not exist. Since the last term exhausted does not exist, we return -1.
}