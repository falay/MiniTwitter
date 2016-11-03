/*** Design a mini Twitter ***/

Designer: Ching Tzu Chen
Date: 2016/11/3

Inspired by the leetcode OJ:
https://leetcode.com/problems/design-twitter/


/***Features***/
A simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. 
The design supports the following methods:

postTweet(userId, tweetId): Compose a new tweet.

getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.

follow(followerId, followeeId): Follower follows a followee.

unfollow(followerId, followeeId): Follower unfollows a followee.