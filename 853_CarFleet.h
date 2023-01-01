#pragma once
#include "Common.h"

struct Car
{
    int position;
    int speed;
};

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {

        int n = position.size();
        vector<Car> cars(n);
        for (int i = 0; i < n; i++)
        {
            cars[i].position = position[i];
            cars[i].speed = speed[i];
        }
        sort(cars.begin(), cars.end(), [](const Car &car1, const Car &car2)
             { return car1.position < car2.position; });
        stack<Car> fleets;
        for (auto &car : cars)
        {
            while (!fleets.empty())
            {
                if (canMerge(fleets.top(), car, target))
                {
                    fleets.pop();
                }
                else
                {
                    break;
                }
            }
            fleets.emplace(car);
        }
        return fleets.size();
    }

private:
    bool canMerge(const Car &car1, const Car &car2, int target)
    {
        long v1 = target - car1.position;
        long v2 = target - car2.position;
        return v1 * car2.speed <= v2 * car1.speed;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    EXPECT_EQ(solution.carFleet(12, position, speed), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> position = {3};
    vector<int> speed = {3};
    EXPECT_EQ(solution.carFleet(10, position, speed), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> position = {0, 2, 4};
    vector<int> speed = {4, 2, 1};
    EXPECT_EQ(solution.carFleet(100, position, speed), 1);
}