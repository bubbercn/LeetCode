#pragma once
#include "Common.h"

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        init(n);
        
        int total = 1;
        for (int i = 1; i <= n; i++)
        {
            total *= i;
        }
        
        return helper(total, k);
    }
private:
    void init(int n)
    {
        numbers = vector<char>(n, '0');
        for (size_t i = 0; i < n; i++)
        {
            numbers[i] = '1' + i;
        }
        
        N = n;
    }
    
    string helper(int total, int k)
    {
        total /= N;
        int index = (k - 1) / total;
        string temp(1, numbers[index]);
        numbers.erase(numbers.begin() + index);
        
        k -= (index) * total;
        N--;
        
        if (N == 0)
        {
            return temp;
        }
        else
        {
            return temp + helper(total, k);
        }
    }
    
    vector<char> numbers;
    int N;
};

void Test()
{
    Solution solution;
    assert(solution.getPermutation(3, 3) == "213");
    assert(solution.getPermutation(4, 9) == "2314");
}
