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
        if (lower != leftMap.end() && lower->first > left && lower == leftMap.begin())
            return false;
        lower--;
        return lower->second >= right;
    }

    void removeRange(int left, int right)
    {
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