#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int buy = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                buy = prices[0];
            }
            else if (prices[i] < buy)
            {
                buy = prices[i];
            }
            else
            {
                profit = max(profit, prices[i] - buy);
            }
        }
        return profit;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> prices = {7,1,5,3,6,4};
    assert(solution.maxProfit(prices) == 5);
    
    prices = {7,6,4,3,1};
    assert(solution.maxProfit(prices) == 0);
}
