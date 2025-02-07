#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<int,int>a,pair<int,int>b) {
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>>v;
    for(int i = 0;i < n;i++) {
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),compare);

    vector<pair<int,int>>ans;
    ans.push_back(v[0]);
    int end_time = v[0].second;
    for(int i = 1;i < n;i++) {
        if(v[i].first > end_time) {
            ans.push_back(v[i]);
            end_time = v[i].second;
        }
    }
    return ans.size();
}