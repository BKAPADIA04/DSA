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

    string longestPrefix(string s) {
        ll n = s.size();
        vector<ll>lps = kmp(s);
        ll index = lps[s.size()-1]; // no of characters
        string ans = s.substr(0,index);
        return ans;
    }
};