#pragma once
#include "Common.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> lookUp;
        unordered_set<string> result;
        for (int i = 0; i + 9 < s.length(); i++) {
            string temp = s.substr(i, 10);
            if (!lookUp.emplace(temp).second) {
                result.emplace(temp);
            }
        }
        return {result.begin(), result.end()};
    }
};

void Test()
{
    Solution solution;
    string s;
    vector<string> output;

    // s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    // output = {"AAAAACCCCC", "CCCCCAAAAA"};
    // assert(solution.findRepeatedDnaSequences(s) == output);

    s = "AAAAAAAAAAAA";
    output = {"AAAAAAAAAA"};
    assert(solution.findRepeatedDnaSequences(s) == output);
}
