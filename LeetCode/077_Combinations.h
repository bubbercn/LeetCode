#pragma once
#include "Common.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        this->N = n;
        this->K = k;
        
        while (next())
        {
            result.emplace_back(state);
        }
        
        return result;
    }
private:
    bool next()
    {
        if (state.empty())
        {
            state = vector<int>(K, 0);
            record = vector<bool>(N + 1, false);
            for (int i = 0; i < K; i++)
            {
                state[i] = i + 1;
                record[state[i]] = true;
            }
            return true;
        }
        else
        {
            return nextone(K - 1);
        }
    }
    bool nextone(int x)
    {
        if (x < 0)
            return false;
        record[state[x]] = false;
        int min = state[x] + 1;
        if (pickone(x, min))
        {
            return true;
        }
        else
        {
            return nextone(x - 1);
        }
    }
    bool pickone(int x, int min)
    {
        int i = min;
        for (; i <= N; i++)
        {
            if (!record[i])
            {
                state[x] = i;
                record[i] = true;
                if (x < K - 1)
                {
                    if (pickone(x + 1, i + 1))
                    {
                        return true;
                    }
                    else
                    {
                        record[i] = false;
                    }
                }
                else
                {
                    return true;
                }

            }
        }
        return false;
    }
    
    int N, K;
    vector<int> state;
    vector<bool> record;
};

void Test()
{
    Solution solution;
    //solution.combine(4, 2);
    //solution.combine(0, 0);
    solution.combine(5, 3);
}
