#pragma once
#include "Common.h"

class Solution
{
public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center), distribution(0, 1)
    {
    }

    vector<double> randPoint()
    {
        double r = radius * sqrt(distribution(generator));
        double angle = 2 * M_PI * distribution(generator);
        return {x_center + r * cos(angle), y_center + r * sin(angle)};
    }

    Solution() {}

private:
    double radius;
    double x_center;
    double y_center;
    default_random_engine generator;
    uniform_real_distribution<double> distribution;
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
