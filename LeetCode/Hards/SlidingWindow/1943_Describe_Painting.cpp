#define ll long long
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<ll,ll>m;
        for(ll i = 0;i < segments.size();i++) {
            m[segments[i][0]] += segments[i][2];
            m[segments[i][1]] -= segments[i][2];
        }

        vector<ll>posn,pre; ll curr = 0;
        for(auto it:m) {
            posn.push_back(it.first);
            curr += it.second;
            pre.push_back(curr);
        }

        vector<vector<ll>>answer;
        for(ll i = 1;i < posn.size();i++) {
            if(pre[i-1] == 0) continue;
            vector<ll>tempo; tempo.push_back(posn[i-1]); tempo.push_back(posn[i]); 
            tempo.push_back(pre[i-1]);
            answer.push_back(tempo); 
        }
        return answer;
    }
};
