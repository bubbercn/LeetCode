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

class disjoint_set_union
{
public:
    disjoint_set_union(int n)
    {
        data.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            data[i] = i;
        }
    }
    int find(int input)
    {
        while (data.at(input) != input)
        {
            input = data.at(input);
        }
        return input;
    }
    int merge(int input1, int input2)
    {
        return data.at(input2) = input1;
    }
    int peek(int input)
    {
        return data.at(input);
    }
    void reset()
    {
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = i;
        }
    }

private:
    vector<int> data;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        disjoint_set_union lookup(2001);
        for (auto employee : employees)
        {
            for (auto child : employee->subordinates)
            {
                if (child != id)
                {
                    lookup.merge(employee->id, child);
                }
            }
        }
        int result = 0;
        for (auto employee : employees)
        {
            if (lookup.find(employee->id) == id)
                result += employee->importance;
        }
        return result;
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
