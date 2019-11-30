#pragma once
#include "Common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted(strs);
        for (auto& i : sorted)
        {
            sort(i.begin(), i.end());
        }
        map<string, vector<string>> temp;
        for (int i = 0; i < sorted.size(); i++)
        {
            temp[sorted[i]].emplace_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto& i : temp)
        {
            result.emplace_back(i.second);
        }
        return result;
    }
};

void Test()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    solution.groupAnagrams(input);
}
