#pragma once
#include "Common.h"

struct PrefixTree
{
    unique_ptr<PrefixTree> mChildren[2];
    void insert(int num)
    {
        PrefixTree* parent = this;
        for (int i = MaxBitsLength - 1; i >= 0; i--)
        {
            int bit = (((1 << i) & num) == 0) ? 0 : 1;
            if (parent->mChildren[bit].get() == nullptr)
            {
                parent->mChildren[bit].reset(new PrefixTree());
            }
            parent = parent->mChildren[bit].get();
        }
    }
    int search(int num)
    {
        int target = 0;
        PrefixTree* parent = this;
        for (int i = MaxBitsLength - 1; i >= 0; i--)
        {
            int bit = 0;
            if (parent->mChildren[0].get() == nullptr)
            {
                bit = 1;
            }
            else
            {
                if (parent->mChildren[1].get() == nullptr)
                {
                    bit = 0;
                }
                else
                {
                    bit = (((1 << i) & num) == 0) ? 1 : 0;
                }
            }
            target |= (bit << i);
            parent = parent->mChildren[bit].get();
        }
        return target;
    }
private:
    static constexpr int MaxBitsLength = 31; 
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        unique_ptr<PrefixTree> root(new PrefixTree());
        for (auto i : nums)
        {
            root->insert(i);
        }
        int result = 0;
        for (auto i : nums)
        {
            result = max(result, i ^ root->search(i));
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
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    EXPECT_EQ(solution.findMaximumXOR(nums), 28);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0};
    EXPECT_EQ(solution.findMaximumXOR(nums), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, 4};
    EXPECT_EQ(solution.findMaximumXOR(nums), 6);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<int> nums = {8, 10, 2};
    EXPECT_EQ(solution.findMaximumXOR(nums), 10);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    EXPECT_EQ(solution.findMaximumXOR(nums), 127);
}
