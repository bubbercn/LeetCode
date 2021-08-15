#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        return splitString(s, 4);
    }

private:
    vector<string> splitString(const string &s, int n)
    {
        if (s.empty())
            return {};

        if (s.length() > 12)
            return {};

        vector<string> result;
        int i = 1;
        for (; i <= s.length() && i <= 3; i++)
        {
            string ip = s.substr(0, i);
            if (isValidIp(ip))
            {
                if (n == 1)
                {
                    if (i == s.length())
                    {
                        result.emplace_back(ip);
                    }
                }
                else
                {
                    for (auto& j : splitString(s.substr(i), n - 1))
                    {
                        result.emplace_back(ip + "." + j);
                    }
                }
            }
        }

        return result;
    }

    bool isValidIp(const string& s)
    {
        int ipValue = atoi(&(s.at(0)));
        if (ipValue > 255)
            return false;
        
        if (to_string(ipValue).length() != s.length())
            return false;

        return true;
    }
};

void Test()
{
    // string input = "25525511135";
    string input = "010010";
    Solution solution;
    auto i = solution.restoreIpAddresses(input);
}