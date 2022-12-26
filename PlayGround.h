#pragma once
#include "Common.h"

class Solution
{
public:
    int takeCharacters(string_view s, int k)
    {
        vector<int> count(3);
        for (auto c : s)
        {
            count[c - 'a']++;
        }
        for (int i = 0; i < 3; i++)
        {
            if (count[i] < k)
                return -1;
        }

        int n = s.length();
        count.assign(3, 0);
        int result = 0;
        int begin = 0;
        int end = n - 1;
        stack<char> left;
        stack<char> right;
        while (count[0] < k or count[1] < k or count[2] < k)
        {
            count[s[begin] - 'a']++;
            left.emplace(s[begin]);
            count[s[end] - 'a']++;
            right.emplace(s[end]);
            begin++;
            end--;
        }
        while (!left.empty() and count[left.top() - 'a'] > k)
        {
            count[left.top() - 'a']--;
            left.pop();
        }
        while (!right.empty() and count[right.top() - 'a'] > k)
        {
            count[right.top() - 'a']--;
            right.pop();
        }

        result = left.size() + right.size();
        
        count.assign(3, 0);
        begin = 0;
        while (count[0] < k or count[1] < k or count[2] < k)
        {
            count[s[begin] - 'a']++;
            begin++;
        }

        result = min(result, begin);

        count.assign(3, 0);
        end = n - 1;
        while (count[0] < k or count[1] < k or count[2] < k)
        {
            count[s[end] - 'a']++;
            end--;
        }
        result =  min(result, n - end - 1);

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
    // EXPECT_EQ(solution.XXX(), 0);
}
