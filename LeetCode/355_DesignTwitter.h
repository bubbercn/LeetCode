#pragma once
#include "Common.h"

class Twitter
{
public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        if (users.count(userId) == 0)
        {
            addUser(userId);
        }
        users[userId].posts.insert({Post::curIndex++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        if (users.count(userId) == 0)
            return {};

        vector<int> result;
        result.reserve(10);
        auto compare = [](const set<Post>::const_iterator &it1, const set<Post>::const_iterator &it2) {
            return *it1 < *it2;
        };
        map<set<Post>::const_iterator, set<Post>::const_iterator, decltype(compare)> newsFeed(compare);
        User &user = users[userId];
        if (!user.posts.empty())
        {
            newsFeed.emplace(user.posts.begin(), user.posts.end());
        }
        for (const auto &followeeID : user.followeeIDs)
        {
            User &user = users[followeeID];
            if (!user.posts.empty())
            {
                newsFeed.emplace(user.posts.begin(), user.posts.end());
            }
        }
        while (result.size() < 10 || !newsFeed.empty())
        {
            result.emplace_back(newsFeed.begin()->first->id);
            auto [first, second] = *newsFeed.begin();
            newsFeed.erase(newsFeed.begin());
            if (first++; first != second)
            {
                newsFeed.emplace(first, second);
            }
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return;
        auto follower = users.find(followerId);
        if (follower == users.end())
            return;
        follower->second.followeeIDs.erase(followerId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return;
        auto follower = users.find(followerId);
        if (follower == users.end())
            return;
        auto followee = users.find(followeeId);
        if (followee == users.end())
            return;
        follower->second.followeeIDs.emplace(followerId);
    }

private:
    struct Post
    {
        inline static int curIndex = 0;
        int index;
        int id;
        bool operator<(const Post &post) const
        {
            return index < post.index;
        }
    };
    struct User
    {
        set<Post> posts;
        set<int> followeeIDs;
    };
    unordered_map<int, User> users;
    void addUser(int userID)
    {
        users.insert({userID, {{}, {}}});
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    Twitter twitter;
    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    EXPECT_EQ(twitter.getNewsFeed(1), vector<int>{5});

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    EXPECT_EQ(twitter.getNewsFeed(1), vector<int>({6, 5}));

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    twitter.getNewsFeed(1);
    EXPECT_EQ(twitter.getNewsFeed(1), vector<int>{5});
}