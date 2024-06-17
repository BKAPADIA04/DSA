#include <bits/stdc++.h>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n == 0) return "";
    if(n == 1) return strs[0];

    // lexicographic sort makes it sure that the elements except the first and last would have first-last waale characters
    // eg = flower,flow,flight
    // sort -> flight,flow,flower

    // f in first and last ... so in flow as well..... similarly for fl

    sort(strs.begin(),strs.end());

    // checking for min between first and last to reduce the computation
    int mini = min(strs[0].size(),strs[n - 1].size());

    string answer = "";
    for(int i = 0;i < mini;i++) {
        if(strs[0][i] != strs[n-1][i]) break;
        answer += strs[0][i];
    }
    return answer;
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    vector<string>strs1 = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs) << endl;
    cout << longestCommonPrefix(strs1) << endl;
}