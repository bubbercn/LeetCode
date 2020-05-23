#pragma once
#include "Common.h"

bool cmp(const string& s1, const string& s2)
{
    auto i = s1.begin(), j = s2.begin();
    for (; i != s2.end(); i++, j++) {
        if (i == s1.end()) {
            i = s2.begin();
        }
        
        if (j == s2.end()) {
            j = s1.begin();
        }

        if (*i > *j) {
            return true;
        }
        if (*i < *j) {
            return false;
        }
    }
    
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<string> numStrs(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numStrs[i] = atoi(nums[i]);
        }
        
        sort(numStrs.begin(), numStrs.end(), cmp);
        
        ostringstream output;
        for (auto i = numStrs.begin(); i != numStrs.end(); i++)
        {
            output << *i;
            if (i == numStrs.begin() && *i == "0")
                break;
        }
        
        return output.str();
    }
private:
    string atoi(int n)
    {
        ostringstream outStream;
        outStream << n;
        return outStream.str();
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
//    nums = {10,2};
//    assert(solution.largestNumber(nums) == "210");
    
    nums = {3,30,34,5,9};
    assert(solution.largestNumber(nums) == "9534330");
}
