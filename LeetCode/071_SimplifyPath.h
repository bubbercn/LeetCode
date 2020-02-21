#pragma once
#include "Common.h"

class Solution {
public:
    string simplifyPath(string path)
    {
        char* input = &path[0];
        char* token;
        
        deque<string> directories;
        token = strtok(input, "/");
        while (token != nullptr)
        {
            directories.emplace_back(token);
            token = strtok(nullptr, "/");
        }
        
        for (auto i = directories.begin(); i != directories.end();)
        {
            if (*i == ".")
            {
                i = directories.erase(i);
            }
            else if (*i == "..")
            {
                if (i != directories.begin())
                {
                    i = directories.erase(i - 1);
                }
                i = directories.erase(i);
            }
            else
            {
                i++;
            }
        }
        
        string result;
        for (auto i = directories.begin(); i != directories.end(); i++)
        {
            result += "/";
            result += *i;
        }
        
        return result.empty() ? "/" : result;
    }
};

void Test()
{
    Solution solution;
    assert(solution.simplifyPath("/home/") == "/home");
    assert(solution.simplifyPath("/../") == "/");
    assert(solution.simplifyPath("/home//foo/") == "/home/foo");
    assert(solution.simplifyPath("/a/./b/../../c/") == "/c");
    assert(solution.simplifyPath("/a/../../b/../c//.//") == "/c");
    assert(solution.simplifyPath("/a//b////c/d//././/..") == "/a/b/c");
}
