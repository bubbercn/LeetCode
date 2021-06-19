#pragma once
#include "Common.h"

class Solution
{
public:
    Solution(double radius, double x_center, double y_center)
    {

    }

    vector<double> randPoint()
    {
        return {};
    }

    Solution() {}
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    auto obj = make_unique<Solution>(1.0, 0.0, 0.0);
    vector<double> param_1 = obj->randPoint();
}
