#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector ;

struct Tweet
{
	int tweetID ;
	int timeStamp ;
	
	Tweet(int Tid, int Time) : tweetID(Tid), timeStamp(Time) {}
} ;


class Twitter 
{
	public:
    /** Initialize the data structure here. */
    Twitter() ;
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) ;
	
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) ;
    
	/**  Retrieve the next latest tweet among all the articles **/
	int getNextNews(int Uid, vector<int>& newsIndex) ;
	
	/** Determine if Uid has any article(tweet) or not **/
	bool hasArticles(int Uid, vector<int> newsIndex) ;
	
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) ;
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) ;
	
private:	
	std::unordered_map<int,vector<Tweet>> postedTweets ;
	std::unordered_map<int,vector<int>> friends ;
	int CurTime ;	
};


#endif //** TWITTER_HPP **//
