#pragma once
#include "Common.h"

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        vector<int> candies(ratings.size(), 1);
        
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        for (int i = ratings.size() -2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            sum += candies[i];
        }
        
        return sum;
    }
};

void Test()
{
    Solution solution;
    vector<int> ratings;
    
    ratings = {1, 0, 2};
    assert(solution.candy(ratings) == 5);

    ratings = {1, 2, 2};
    assert(solution.candy(ratings) == 4);
    
    ratings = {1, 3, 2, 2, 1};
    assert(solution.candy(ratings) == 7);
}
