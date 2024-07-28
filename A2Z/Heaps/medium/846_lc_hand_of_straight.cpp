#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if((n % groupSize) != 0) return false;
    if(groupSize == 1) return true;
    unordered_map<int,int>freq_map;
    for(int i = 0;i < n;i++){
        freq_map[hand[i]]++;
    }       
    priority_queue<p,vector<p>,greater<p>>pq;
    for(auto entry:freq_map) {
        pq.push({entry.first,entry.second});
    }

    queue<p>q;
    while(!pq.empty()) {
        pair <int,int> top = pq.top();
        int ele = top.first;
        int freq = top.second;
        pq.pop();
        for(int i = 1;i < groupSize;i++) {
            if(!pq.empty() && (pq.top().first == (ele + i))) {
                int ele_ = pq.top().first;
                int freq_ =  pq.top().second;
                pq.pop();
                if(freq_ > 1) q.push({ele_,freq_ - 1});
            }
            else return false;
        }
        while(!q.empty()) {
            pq.push(q.front());
            q.pop();
        }
        if(freq > 1) pq.push({ele,freq-1});
    }
    return true;
}

int main() {
    vector<int>hand = {1,2,3,6,2,3,4,7,8};
    cout << isNStraightHand(hand,3) << endl;
}