#pragma once
#include "Common.h"

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<Employee *> employees;
    employees.emplace_back(new Employee({1, 5, {2, 3}}));
    employees.emplace_back(new Employee({2, 3, {}}));
    employees.emplace_back(new Employee({3, 3, {}}));
    EXPECT_EQ(solution.getImportance(employees, 1), 11);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<Employee *> employees;
    employees.emplace_back(new Employee({1, 2, {5}}));
    employees.emplace_back(new Employee({5, -3, {}}));
    EXPECT_EQ(solution.getImportance(employees, 5), -3);
}
