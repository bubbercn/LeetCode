#pragma once
#include "Common.h"

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> versions1 = getVersions(version1);
        vector<int> versions2 = getVersions(version2);
        auto i1 = versions1.begin(), i2 = versions2.begin();
        for (; i1 != versions1.end() && i2 != versions2.end(); i1++, i2++)
        {
            if (*i1 > *i2)
            {
                return 1;
            }
            else if (*i1 < *i2)
            {
                return -1;
            }
        }
        
        for (; i1 != versions1.end(); i1++)
        {
            if (*i1 != 0)
                return 1;
        }
        
        for (; i2 != versions2.end(); i2++)
        {
            if (*i2 != 0)
                return -1;
        }
        
        return 0;
    }
private:
    vector<int> getVersions(string& version)
    {
        if (version.empty())
            return {};
        char* input = &version[0];
        char* token;
        
        vector<int> versions;
        token = strtok(input, ".");
        while (token != nullptr)
        {
            versions.emplace_back(atoi(token));
            token = strtok(nullptr, ".");
        }
        
        return versions;
    }
};

void Test()
{
    Solution solution;
    string version1, version2;
    
    version1 = "0.1";
    version2 = "1.1";
    assert(solution.compareVersion(version1, version2) == -1);

    version1 = "1.0.1";
    version2 = "1";
    assert(solution.compareVersion(version1, version2) == 1);

    version1 = "7.5.2.4";
    version2 = "7.5.3";
    assert(solution.compareVersion(version1, version2) == -1);
    
    version1 = "1.01";
    version2 = "1.001";
    assert(solution.compareVersion(version1, version2) == 0);
    
    version1 = "1.0";
    version2 = "1.0.0";
    assert(solution.compareVersion(version1, version2) == 0);
}
