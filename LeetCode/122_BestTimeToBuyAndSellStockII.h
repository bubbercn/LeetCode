#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int currentProfit = 0;
        int totalProfit = 0;
        int buy = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                buy = prices[0];
            }
            else if (prices[i] < prices[i - 1])
            {
                totalProfit += currentProfit;
                buy = prices[i];
                currentProfit = 0;
            }
            else
            {
                currentProfit = max(currentProfit, prices[i] - buy);
            }
        }
        totalProfit += currentProfit;
        return totalProfit;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> prices = {7,1,5,3,6,4};
    assert(solution.maxProfit(prices) == 7);
    
    prices = {1,2,3,4,5};
    assert(solution.maxProfit(prices) == 4);
}
