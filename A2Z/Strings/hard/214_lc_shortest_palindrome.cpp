#define ll long long
class Solution {
public:

    vector<ll>kmp(string s) {
        vector<ll>lps(s.size());
        for(ll i = 1;i < s.size();i++) {
            ll prev_index = lps[i-1];

            while(prev_index > 0 && s[i] != s[prev_index]) prev_index = lps[prev_index - 1];

            lps[i] = prev_index + (s[i] == s[prev_index] ? 1 : 0);
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        string check = s + "#" + temp;
        vector<ll>lps = kmp(check);
        ll index = lps[lps.size()-1];
        string tempo = s.substr(index);
        reverse(tempo.begin(),tempo.end());
        string ans = tempo + s;
        return ans;
    }
};