#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    // int n = s.size(); int m = t.size();
    // string str1 = s; string str2 = t;
    // sort(str1.begin(),str1.end());
    // sort(str2.begin(),str2.end());
    // if(str1 == str2) return true;
    // return false;


    int n = s.size(); int m = t.size();
    if(n != m) return false;
    map<char,int>s_map; map<char,int>t_map;

    for(int i = 0;i < n;i++) {
        if(s_map.find(s[i]) != s_map.end())  { s_map[s[i]]++;}
        else s_map[s[i]] = 1;

        if(t_map.find(t[i]) != t_map.end())  { t_map[t[i]]++;}
        else t_map[t[i]] = 1;
    }

    for(int i = 0;i < s_map.size();i++) {
        if(s_map[s[i]] != t_map[s[i]]) return false;
    }
    return true;
}

int main() {
    cout << isAnagram("anagram","nagaram") << endl;
}