#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        vector<int> leftProfits = getLeftProfits(prices);
        vector<int> rightProfits = getRightProfits(prices);
        
        int maxProfit = 0;
        auto i = leftProfits.begin();
        auto j = rightProfits.begin();
        while (i != leftProfits.end() || j != rightProfits.end())
        {
            maxProfit = max(maxProfit, *i + *j);
            i++;
            j++;
        }
        return maxProfit;
    }
private:
    vector<int> getLeftProfits(const vector<int>& prices)
    {
        vector<int> result(prices.size(), 0);
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
            result[i] = profit;
        }
        return result;
    }
    vector<int> getRightProfits(const vector<int>& prices)
    {
        vector<int> result(prices.size(), 0);
        int profit = 0;
        int sell = 0;
        for (int i = static_cast<int>(prices.size() - 1); i >= 0; i--)
        {
            if (i == prices.size() - 1)
            {
                sell = prices[prices.size() - 1];
            }
            else if (prices[i] > sell)
            {
                sell = prices[i];
            }
            else
            {
                profit = max(profit, sell - prices[i]);
            }
            result[i] = profit;
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> prices = {3,3,5,0,0,3,1,4};
    assert(solution.maxProfit(prices) == 6);
    
    prices = {1,2,3,4,5};
    assert(solution.maxProfit(prices) == 4);
    
    prices = {7,6,4,3,1};
    assert(solution.maxProfit(prices) == 0);
}
