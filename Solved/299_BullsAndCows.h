#pragma once
#include "Common.h"

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0;
        int cow = 0;
        unordered_map<char, int> lookup;
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                bull++;
                guess[i] = ' ';
            }
            else
            {
                lookup[secret[i]]++;
            }
        }
        for (int i = 0; i < secret.length(); i++)
        {
            if (guess[i] != ' ')
            {
                auto it = lookup.find(guess[i]);
                if (it != lookup.end() && it->second > 0)
                {
                    cow++;
                    it->second--;
                }
            }
        }
        ostringstream stream;
        stream << bull << "A" << cow << "B";
        return stream.str();
    }
};

void Test()
{
    Solution solution;

    assert(solution.getHint("1807", "7810") == "1A3B");
    
    assert(solution.getHint("1123", "0111") == "1A1B");
}