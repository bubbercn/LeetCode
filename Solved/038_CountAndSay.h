#pragma once
#include "Common.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }
        else
        {
            string previousString = countAndSay(n - 1);
            int count = 0;
            char pc = *previousString.begin();
            string result;
            for (char c : previousString)
            {
                if (c != pc)
                {
                    result += ('0' + count);
                    result += pc;
                    count = 1;
                    pc = c;
                }
                else
                {
                    count++;
                }
            }
            result += ('0' + count);
            result += pc;
            
            return result;
        }
    }
};

void Test()
{
    Solution solution;
    assert(solution.countAndSay(1) == "1");
    assert(solution.countAndSay(2) == "11");
    assert(solution.countAndSay(3) == "21");
    assert(solution.countAndSay(4) == "1211");
    assert(solution.countAndSay(5) == "111221");
}
