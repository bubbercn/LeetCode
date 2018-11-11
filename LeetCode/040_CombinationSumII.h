#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        set<vector<int>> resultSet;
        
        sort(candidates.begin(), candidates.end());
        
        deque<int> currentCombination;
        deque<int> currentIndexes;
        
        int currentCandidateIndex = 0;
        int total = 0;
        
        while (currentCandidateIndex < candidates.size())
        {
            while (total < target && currentCandidateIndex < candidates.size())
            {
                currentCombination.emplace_back(candidates[currentCandidateIndex]);
                currentIndexes.emplace_back(currentCandidateIndex);
                total += candidates[currentCandidateIndex++];
            }
            if (total == target)
            {
                vector<int> temp(currentCombination.begin(), currentCombination.end());
                resultSet.emplace(temp);
            }
            
            total -= currentCombination.back();
            currentCombination.pop_back();
            currentCandidateIndex = currentIndexes.back();
            currentIndexes.pop_back();
            
            
            if (!currentCombination.empty())
            {
                total -= currentCombination.back();
                currentCombination.pop_back();
                currentCandidateIndex = currentIndexes.back();
                currentIndexes.pop_back();
            }
            
            currentCandidateIndex++;
            
            while (currentCandidateIndex >= candidates.size() && !currentCombination.empty())
            {
                total -= currentCombination.back();
                currentCombination.pop_back();
                currentCandidateIndex = currentIndexes.back();
                currentIndexes.pop_back();
                currentCandidateIndex++;
            }
        }
        
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};

void Test()
{
    Solution solution;
    
    vector<int> input3 = {4, 4};
    vector<vector<int>> output3 = {};
    assert(solution.combinationSum2(input3, 6) == output3);
    
    vector<int> input1 = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> output1 =
    {
        {1, 1, 6},
        {1, 2, 5},
        {1, 7},
        {2, 6}
    };
    assert(solution.combinationSum2(input1, 8) == output1);
    
    vector<int> input2 = {2, 5, 2, 1, 2};
    vector<vector<int>> output2 =
    {
        {1, 2, 2},
        {5}
    };
    assert(solution.combinationSum2(input2, 5) == output2);
}
