#include <bits/stdc++.h>
using namespace std;

vector<int> check(string &s) {
    int n = s.size();
    unordered_map<char,int>firstOcc; unordered_map<char,int>lastOcc;
    for(int i = 0;i < n;i++) {
        if(firstOcc.find(s[i]) == firstOcc.end()) {
            firstOcc[s[i]] = i;
        }
        lastOcc[s[i]] = i;
    }
    
    vector<pair<int,int>>intervals;

    for(auto it : firstOcc) {
        intervals.push_back({it.second,lastOcc[it.first]});
    }

    // for(auto it:intervals) cout << it.first << " " << it.second << endl;

    sort(intervals.begin(),intervals.end());
    // for(auto it:intervals) cout << it.first << " " << it.second << endl;

    int last = -1;
    int ans = 0;

    vector<int>answer;

    for(int i = 0;i < intervals.size();i++) {
        int start = intervals[i].first; int end = intervals[i].second;
        if(start > last) {
            ans++;
            answer.push_back(last);
            last = end;
        }
        else {
            last = max(last,end);
        }
        // cout << start << " " << end << " " << last << endl;
    }
    answer.push_back(n - 1);

    vector<int>finalAns;
    for(int i = 1;i < answer.size();i++) {
        finalAns.push_back(answer[i] - answer[i-1]);
    }
    return finalAns;
}


int main() {
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        vector<int>ans = check(str);
        for(auto it:ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
