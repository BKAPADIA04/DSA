#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    map<int, int, greater<>> freq;
    
    bool valid(int M, int T) {
        for (auto &[n, cnt] : freq) {
            if (n <= M) break;
            T -= (ll)cnt * (n - M);
            if (T <= 0) return true;
        }
        return T <= 0;
    }
    
    int maxProfit(vector<int>& inventory, int orders) {
        for (int n : inventory) freq[n]++;
        ll low = 0, high = *max_element(begin(inventory), end(inventory));
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (valid(mid, orders)) low = mid + 1;
            else high = mid - 1;
        }
        
        ll answer = 0;
        for (auto &[n, cnt] : freq) {
            if (n <= low) break;
            orders -= cnt * (n - low);
            answer = (answer + ((n + low + 1) * (n - low) / 2 % mod * cnt % mod)) % mod;
        }
        
        if (orders > 0) answer = (answer + low * orders % mod) % mod;
        return answer;
    }
};
