#pragma once
#include "Common.h"

class RangeModule
{
public:
    RangeModule()
    {
    }

    void addRange(int left, int right)
    {
        if (queryRange(left, right))
            return;

        auto leftLower = leftMap.lower_bound(left);
        auto leftUpper = leftMap.upper_bound(right);
        for (auto it = leftLower; it != leftUpper;)
        {
            right = max(right, it->second);
            rightMap.erase(it->second);
            it = leftMap.erase(it);
        }
        auto rightLower = rightMap.lower_bound(left);
        auto rightUpper = rightMap.upper_bound(right);
        for (auto it = rightLower; it != rightUpper;)
        {
            int leftTemp = it->second->first;
            left = min(left, leftTemp);
            it = rightMap.erase(it);
            leftMap.erase(leftTemp);
        }
        auto it = leftMap.emplace(left, right).first;
        rightMap.emplace(right, it);
    }

    bool queryRange(int left, int right)
    {
        if (leftMap.empty())
            return false;
        auto lower = leftMap.lower_bound(left);
        if (lower == leftMap.begin() && lower->first > left)
            return false;

        if (lower == leftMap.end() || lower->first > left)
            lower--;
        return lower->second >= right;
    }

    void removeRange(int left, int right)
    {
        if (leftMap.empty())
            return;

        auto leftLower = leftMap.lower_bound(left);
        if (leftLower != leftMap.begin())
        {
            auto it = leftLower;
            it--;
            if (it->second > right)
            {
                int ll = it->first;
                int rr = it->second;
                rightMap.erase(rr);
                leftMap.erase(it);
                it = leftMap.emplace(ll, left).first;
                rightMap.emplace(left, it);
                it = leftMap.emplace(right, rr).first;
                rightMap.emplace(rr, it);
                return;
            }
        }

        auto leftUpper = leftMap.upper_bound(right);
        for (auto it = leftLower; it != leftUpper;)
        {
            int tempRight = it->second;
            rightMap.erase(tempRight);
            it = leftMap.erase(it);
            if (tempRight > right)
            {
                auto temp = leftMap.emplace(right, tempRight).first;
                rightMap.emplace(tempRight, temp);
            }
        }
        auto rightLower = rightMap.lower_bound(left);
        auto rightUpper = rightMap.upper_bound(right);
        for (auto it = rightLower; it != rightUpper;)
        {
            int leftTemp = it->second->first;
            it = rightMap.erase(it);
            leftMap.erase(leftTemp);
            if (leftTemp < left)
            {
                auto temp = leftMap.emplace(leftTemp, left).first;
                rightMap.emplace(left, temp);
                break;
            }
        }
    }

private:
    map<int, int> leftMap;
    map<int, map<int, int>::const_iterator> rightMap;
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
    RangeModule rangeModule;
    EXPECT_FALSE(rangeModule.queryRange(13, 15));
    rangeModule.addRange(10, 20);
    EXPECT_FALSE(rangeModule.queryRange(9, 15));
    EXPECT_TRUE(rangeModule.queryRange(13, 15));
    rangeModule.removeRange(14, 16);
    EXPECT_TRUE(rangeModule.queryRange(10, 14));
    EXPECT_FALSE(rangeModule.queryRange(13, 15));
    EXPECT_TRUE(rangeModule.queryRange(16, 17));
}

TEST_F(LeetCodeTest, Example2)
{
    RangeModule rangeModule;
    rangeModule.addRange(6, 8);
    rangeModule.removeRange(7, 8);
    rangeModule.removeRange(8, 9);
    rangeModule.addRange(8, 9);
    rangeModule.removeRange(1, 3);
    rangeModule.addRange(1, 8);
    EXPECT_TRUE(rangeModule.queryRange(2, 4));
    EXPECT_TRUE(rangeModule.queryRange(2, 9));
    EXPECT_TRUE(rangeModule.queryRange(4, 6));
}