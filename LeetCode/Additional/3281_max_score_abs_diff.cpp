#define ll long long
class Solution {
public:

    ll check(vector<int>&start,ll d,ll mid) {
        ll n = start.size();
        ll st = start[0];
        for(ll i = 1;i < n;i++) {
            if(st + mid > start[i] + d) return false;
            st = max(start[i] * 1ll,st + mid);
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        ll low = 0;
        ll high = *max_element(start.begin(),start.end()) + d;
        ll answer = 0;
        while(low <= high) {
            ll mid = (low + high) / 2;
            cout << mid << endl;
            if(check(start,d,mid)) {
                answer = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return (int)answer;
    }
};
