#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++)
        {
            set<vector<int>> temp = subset(nums, i);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }

private:
    set<vector<int>> subset(vector<int> &nums, int size)
    {
        if (size == 0)
            return {{}};

        init(size);

        set<vector<int>> result;
        while (nextSubset(nums))
        {
            result.emplace(state);
        }

        return result;
    }

    void init(int size)
    {
        state.clear();
        record = vector<int>(size, -1);
        this->size = size;
    }

    bool nextSubset(vector<int>& nums)
    {
        if (state.empty())
        {
            for (int i = 0; i < size; i++)
            {
                state.emplace_back(nums[i]);
                record[i] = i;
            }
            return true;
        }
        else
        {
            return nextOne(nums, size - 1);
        }
    }
    
    bool nextOne(vector<int>& nums, int x)
    {
        if (x < 0)
            return false;
        
        int min = record[x];
        record[x] = -1;
        if (pickOne(nums, x, min + 1))
        {
            return true;
        }
        else
        {
            return nextOne(nums, x - 1);
        }
    }
    
    bool pickOne(vector<int>& nums, int index, int min)
    {
        for (int i = min; i < nums.size(); i++)
        {
            if (nums[i] > state[index])
            {
                state[index] = nums[i];
                record[index] = i;
                if (index + 1 < size)
                {
                    if (putOne(nums, index + 1, i + 1))
                    {
                        return true;
                    }
                    else
                    {
                        record[index] = -1;
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
    
    bool putOne(vector<int>& nums, int index, int min)
    {
        for (int i = min; i < nums.size(); i++)
        {
            if (nums[i] >= state[index - 1])
            {
                state[index] = nums[i];
                record[index] = i;
                if (index + 1 < size)
                {
                    if (putOne(nums, index + 1, i + 1))
                    {
                        return true;
                    }
                    else
                    {
                        record[index] = -1;
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

    vector<int> state;
    vector<int> record;
    int size;
};

void Test()
{
}