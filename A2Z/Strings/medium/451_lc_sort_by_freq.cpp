#include <bits/stdc++.h>
using namespace std;

bool compare(pair<char,int>&a,pair<char,int>&b) {
    return a.second > b.second; // non-increasing
}


string frequencySort(string s) {
    int n = s.size();
    map<char,int>m;
    for(int i = 0;i < n;i++) {
        m[s[i]]++;
    }

    vector<pair<char, int> > v;
    for(auto it:m) {
        v.push_back(make_pair(it.first,it.second));
    }
    sort(v.begin(),v.end(),compare);
    string ans = "";
    for(auto it:v) {
        for(int i = 0;i < it.second;i++) 
            ans += it.first;
    }
    return ans;
}

int main() {
    cout << frequencySort("cccaaa") << endl;
    unordered_map<char, int> cnt;
}