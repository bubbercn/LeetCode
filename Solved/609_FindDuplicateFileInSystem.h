#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, unordered_set<string>> lookup;
        for (auto& path : paths)
        {
            string_view pathView = path;
            size_t pos = pathView.find_first_of(' ');
            string_view dir = pathView.substr(0, pos);
            pos++;
            while (pos < pathView.size())
            {
                size_t next = pathView.find_first_of('(', pos);
                string_view fileName = pathView.substr(pos, next - pos);
                pos = next + 1;
                next = pathView.find_first_of(')', pos);
                string_view content = pathView.substr(pos, next - pos);
                lookup[string(content)].emplace(string(dir) + "/" + string(fileName));
                pos = next + 2;
            }
        }
        vector<vector<string>> result;
        for (auto& [content, stringSet] : lookup)
        {
            if (stringSet.size() > 1)
            {
                vector<string> temp(stringSet.begin(), stringSet.end());
                result.emplace_back(temp);
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> output = {
        {"root/a/2.txt", "root/c/d/4.txt", "root/4.txt"},
        {"root/a/1.txt", "root/c/3.txt"},
    };
    EXPECT_EQ(solution.findDuplicate(paths), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)"};
    vector<vector<string>> output = {
        {"root/a/2.txt", "root/c/d/4.txt"},
        {"root/a/1.txt", "root/c/3.txt"},
    };
    EXPECT_EQ(solution.findDuplicate(paths), output);
}