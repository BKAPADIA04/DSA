#define ll long long
class Solution {
public:
    long long calculateScore(string s) {
        ll n = s.size();
        ll answer = 0ll;
        vector<stack<ll>>st(26);
        for(ll i = 0;i < n;i++) {
            int gap = s[i] - 'a';
            int rev = ('z' - gap) - 'a';
            if(st[rev].size() > 0) {
                answer += (i - st[rev].top());
                st[rev].pop();
            }
            else {
                st[gap].push(i);
            }
        }
        return answer;
    }
};
