#pragma once
#include "Common.h"

class Solution
{
public:
//    struct Combination
//    {
//        vector<int> mCombination;
//        int sum = 0;
//    };
//
//    vector<vector<int>> breadthFirtSearch(vector<int>& candidates, int target)
//    {
//        sort(candidates.begin(), candidates.end());
//
//        set<vector<int>> result;
//
//        vector<Combination> previousCombinationCandidates;
//        for (auto i : candidates)
//        {
//            previousCombinationCandidates.emplace_back(Combination({{i}, i}));
//        }
//
//        while (previousCombinationCandidates.size() != 0)
//        {
//            vector<Combination> currentCombinationCandidates;
//            for (auto i : previousCombinationCandidates)
//            {
//                if (i.sum == target)
//                {
//                    sort(i.mCombination.begin(), i.mCombination.end());
//                    result.emplace(i.mCombination);
//                }
//                else if (i.sum < target)
//                {
//                    for (auto j : candidates)
//                    {
//                        auto temp = i.mCombination;
//                        temp.emplace_back(j);
//                        currentCombinationCandidates.emplace_back(Combination({temp, i.sum + j}));
//                    }
//                }
//            }
//            previousCombinationCandidates = currentCombinationCandidates;
//        }
//
//        return vector<vector<int>> (result.begin(), result.end());
//    }
//
//    vector<vector<int>> bruteForce(vector<int>& candidates, int target)
//    {
//        vector<vector<int>> result;
//
//        sort(candidates.begin(), candidates.end());
//
//        vector<int> maxOccurences(candidates.size(), 0);
//        vector<int> occurrences(maxOccurences);
//
//        for (int i = 0; i < candidates.size(); i++)
//        {
//            maxOccurences[i] = target / candidates[i];
//        }
//
//        occurrences[0] = 1;
//
//        while (*occurrences.rbegin() <= *maxOccurences.rbegin())
//        {
//            int total = 0;
//            for (int i = 0; i < candidates.size(); i++)
//            {
//                if (occurrences[i])
//                {
//                    total += candidates[i] * occurrences[i];
//                }
//                if (total > target)
//                    break;
//            }
//            if (total == target)
//            {
//                vector<int> temp;
//                for (int i = 0; i < occurrences.size(); i++)
//                {
//                    if (occurrences[i] != 0)
//                    {
//                        for (int j = 0; j < occurrences[i]; j++)
//                        {
//                            temp.emplace_back(candidates[i]);
//                        }
//                    }
//                }
//                result.emplace_back(temp);
//            }
//
//            occurrences[0]++;
//
//            for (int i = 0; i < occurrences.size(); i++)
//            {
//                if (occurrences[i] > maxOccurences[i] && i != occurrences.size() - 1)
//                {
//                    occurrences[i] = 0;
//                    occurrences[i + 1]++;
//                }
//            }
//        }
//
//        return result;
//    }
    
    vector<vector<int>> depthFirstSearch(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        
        sort(candidates.begin(), candidates.end());
        
        deque<int> currentCombination;
        deque<int> currentIndexes;
        
        int currentCandidateIndex = 0;
        int total = 0;
        
        while (currentCandidateIndex < candidates.size())
        {
            while (total < target)
            {
                currentCombination.emplace_back(candidates[currentCandidateIndex]);
                currentIndexes.emplace_back(currentCandidateIndex);
                total += candidates[currentCandidateIndex];
            }
            if (total == target)
            {
                vector<int> temp(currentCombination.begin(), currentCombination.end());
                result.emplace_back(temp);
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
        
        return result;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        // return breadthFirtSearch(candidates, target); -- Memory Limit Exceeded
     
        // return bruteForce(candidates, target); -- Time Limit Exceeded
        
        return depthFirstSearch(candidates, target);
    }
};

void Test()
{
    Solution solution;
    
    vector<int> input1 = {2, 3, 6, 7};
    vector<vector<int>> output1 =
    {
        {2, 2, 3},
        {7}
    };
    assert(solution.combinationSum(input1, 7) == output1);
    
    vector<int> input2 = {2, 3, 5};
    vector<vector<int>> output2 =
    {
        {2, 2, 2, 2},
        {2, 3, 3},
        {3, 5}
    };
    assert(solution.combinationSum(input2, 8) == output2);
}
