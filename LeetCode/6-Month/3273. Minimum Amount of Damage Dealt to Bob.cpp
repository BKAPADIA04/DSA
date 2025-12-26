#define ll long long
class Solution {
public:

    static bool comparator(pair<ll,ll>&a, pair<ll,ll>&b) {
        return a.second * b.first < b.second * a.first;
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        ll sum = accumulate(damage.begin(),damage.end(),0ll);
        vector<pair<ll,ll>>pq;
        
        for(ll i = 0;i < damage.size();i++) {
            pq.push_back({damage[i],(ll)(health[i] + power - 1) / (ll)(power)});
        }

        sort(pq.begin(),pq.end(),comparator);

        ll curTime = 0;
        ll answer = 0ll;
        for(ll i = 0;i < pq.size();i++) {
            ll d = pq[i].first;
            ll h = pq[i].second;
            curTime += h;
            answer += curTime * d;
        }
        return answer;
    }
};
