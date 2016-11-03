#include "Twitter.hpp"




Twitter::Twitter() 
{
	CurTime = 0 ;	
}


void Twitter::postTweet(int userId, int tweetId) 
{
	Tweet newPost( tweetId, CurTime++ ) ;
	postedTweets[userId].insert( postedTweets[userId].begin(), newPost ) ;
}

vector<int> Twitter::getNewsFeed(int userId) 
{
    vector<int> newsIndex(friends[userId].size()+1, 0) ;
	vector<int> newsFeed ;
		
	while( newsFeed.size() < 10 && hasArticles(userId, newsIndex) )
		newsFeed.push_back( getNextNews( userId, newsIndex ) ) ;
		
	return newsFeed ;	
}


int Twitter::getNextNews(int Uid, vector<int>& newsIndex)
{
	int curMaxTime  = -1, curMaxIndex = -1, curTid ;
		
	for(int i=0; i<newsIndex.size()-1; i++)
	{
		if( newsIndex[i] >= postedTweets[friends[Uid][i]].size() )
			continue ;
			
		Tweet friendsTweet = postedTweets[friends[Uid][i]][newsIndex[i]] ;
			
		if( curMaxTime < friendsTweet.timeStamp )
		{
			curMaxTime  = friendsTweet.timeStamp ;
			curMaxIndex = i ;
			curTid      = friendsTweet.tweetID ;	
		}			
	}	
		
	if( newsIndex.back() < postedTweets[Uid].size() )
	{	
		Tweet myTweet = postedTweets[Uid][newsIndex.back()] ; 
		if( curMaxTime < myTweet.timeStamp )
		{
			newsIndex.back() ++ ;
			return myTweet.tweetID ;
		}	
	}	

	newsIndex[ curMaxIndex ] ++ ;
	return curTid ;
				
}


bool Twitter::hasArticles(int Uid, vector<int> newsIndex)
{
	for(int i=0; i<newsIndex.size(); i++)
	{
		if( i < newsIndex.size() - 1 )
		{
			if( newsIndex[i] < postedTweets[friends[Uid][i]].size() )
				return true ;	
		}	
		else
		{
			if( newsIndex[i] < postedTweets[Uid].size() )
				return true ;
		}	
	}	
		
	return false ;
}


void Twitter::follow(int followerId, int followeeId) 
{
	if( 
		followerId == followeeId || 
		find(friends[followerId].begin(), friends[followerId].end(), followeeId) != friends[followerId].end()	
	  )
		return ;
		
	friends[ followerId ].push_back( followeeId ) ;						
}
  

void Twitter::unfollow(int followerId, int followeeId) 
{
	if( followerId == followeeId )
		return ;	
			
    for(int i=0; i<friends[followerId].size(); i++)
		if( friends[followerId][i] == followeeId )
		{
			friends[followerId].erase( friends[followerId].begin()+i ) ;
			break ;
		}	
}  



