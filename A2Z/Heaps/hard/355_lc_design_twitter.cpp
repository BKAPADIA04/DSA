#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    map<int,set<int>>friends_map;
    int current;
    priority_queue<vector<int>>pq;
    Twitter() {
        friends_map.clear();
        current = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({++current,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>answer;
        priority_queue<vector<int>> temp = pq;
        int count = 0;
        while(!temp.empty() && count < 10) {
            vector<int>top = temp.top();
            if(top[1] == userId || friends_map[userId].count(top[1])) {
                answer.push_back(top[2]);
                count++;
            }
            temp.pop();
        }
        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        friends_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends_map[followerId].erase(followeeId);
    }
};

