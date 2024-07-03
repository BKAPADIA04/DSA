#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(string str,int start,int end) {
    int n = str.size();
    while(start <= end) {
        if(str[start++] != str[end--]) return false;
    }
    return true;
}

void generate(vector<vector<string>>&ans,vector<string>&check,string s,int index,int n) {
    if(index == n) {
        ans.push_back(check);
        return;
    }

    for(int i = index;i < n;i++) {
        if(isPalindromic(s,index,i)) {
            check.push_back(s.substr(index, i - index + 1));
            generate(ans,check,s,i+1,n);
            check.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>check;
    generate(ans,check,s,0,s.size());
    return ans;
}

int main() {
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}