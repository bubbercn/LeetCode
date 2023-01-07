#pragma once
#include "Common.h"

struct cmp
{
    bool operator()(const pair<int, int> &v1, const pair<int, int> &v2) const
    {
        if ((v1.second - v1.first) / 2 == (v2.second - v2.first) / 2)
            return v1.first < v2.first;
        return v1.second - v1.first > v2.second - v2.first;
    }
};

class ExamRoom
{
public:
    ExamRoom(int n)
    {
        this->n = n;
    }

    int seat()
    {
        if (segments.empty())
        {
            segments.emplace(0, 2 * (n - 1));
            return 0;
        }

        auto [begin, end] = *segments.begin();
        if (end - begin == 1)
            return -1;
        int middle = (begin + end) / 2;
        segments.erase(segments.begin());
        if (begin >= 0)
            segments.emplace(begin, middle);
        if (end < n)
            segments.emplace(middle, end);
        return middle;
    }

    void leave(int p)
    {
        int begin = numeric_limits<int>::max();
        int end = numeric_limits<int>::min();
        bool found = false;
        for (auto it = segments.begin(); it != segments.end();)
        {
            if (it->first == p || it->second == p)
            {
                found = true;
                begin = min(begin, it->first);
                end = max(end, it->second);
                it = segments.erase(it);
            }
            else
            {
                it++;
            }
        }
        if (!found)
            return;

        if ((p == 0 || begin < 0) && (p == n - 1 || end >= n))
            return;

        if (p == 0 || begin < 0)
        {
            segments.emplace(-end, end);
            return;
        }

        if (p == n - 1 || end >= n)
        {
            segments.emplace(begin, 2 * (n - 1) - begin);
            return;
        }

        segments.emplace(begin, end);
    }

private:
    int n;
    set<pair<int, int>, cmp> segments;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    ExamRoom examRoom(10);
    EXPECT_EQ(examRoom.seat(), 0); // return 0, no one is in the room, then the student sits at seat number 0.
    EXPECT_EQ(examRoom.seat(), 9); // return 9, the student sits at the last seat number 9.
    EXPECT_EQ(examRoom.seat(), 4); // return 4, the student sits at the last seat number 4.
    EXPECT_EQ(examRoom.seat(), 2); // return 2, the student sits at the last seat number 2.
    examRoom.leave(4);
    EXPECT_EQ(examRoom.seat(), 5); // return 5, the student sits at the last seat number 5.
}

TEST_F(LeetCodeTest, Failure1)
{
    ExamRoom examRoom(4);
    EXPECT_EQ(examRoom.seat(), 0);
    EXPECT_EQ(examRoom.seat(), 3);
    EXPECT_EQ(examRoom.seat(), 1);
    EXPECT_EQ(examRoom.seat(), 2);
    examRoom.leave(1);
    examRoom.leave(3);
    EXPECT_EQ(examRoom.seat(), 1);
}

TEST_F(LeetCodeTest, Failure2)
{
    ExamRoom examRoom(10);
    EXPECT_EQ(examRoom.seat(), 0);
    EXPECT_EQ(examRoom.seat(), 9);
    EXPECT_EQ(examRoom.seat(), 4);
    examRoom.leave(0);
    examRoom.leave(4);
    EXPECT_EQ(examRoom.seat(), 0);
    EXPECT_EQ(examRoom.seat(), 4);
    EXPECT_EQ(examRoom.seat(), 2);
    EXPECT_EQ(examRoom.seat(), 6);
    EXPECT_EQ(examRoom.seat(), 1);
    EXPECT_EQ(examRoom.seat(), 3);
    EXPECT_EQ(examRoom.seat(), 5);
    EXPECT_EQ(examRoom.seat(), 7);
    EXPECT_EQ(examRoom.seat(), 8);
    examRoom.leave(0);
}