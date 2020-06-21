#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (k <= 0 || k > 9)
            return {};

        this->n = n;
        result.clear();

        vector<int> window(k);
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            window[i] = i + 1;
            sum += window[i];
        }

        dfs(window, sum, window.size() - 1);

        return result;
    }

private:
    void dfs(vector<int> &window, int sum, int cursor)
    {
        if (sum > n)
            return;

        if (sum == n)
        {
            result.emplace_back(window);
            return;
        }

        for (int i = cursor; i >= 0; i--)
        {
            if (i == window.size() - 1)
            {
                if (window[i] == 9)
                {
                    continue;
                }
            }
            else
            {
                if (window[i] == window[i + 1] - 1)
                {
                    continue;
                }
            }
            window[i]++;
            sum++;
            dfs(window, sum, i);
            window[i]--;
            sum--;
        }
    }
    vector<vector<int>> result;
    int n;
};

void Test()
{
    Solution solution;
    //solution.combinationSum3(3, 7);
    solution.combinationSum3(3, 9);
}