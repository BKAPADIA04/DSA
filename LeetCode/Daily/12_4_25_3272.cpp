#define ll long long
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<ll>factorial(n + 1,1);
        for(int i = 1;i < factorial.size();i++) {
            factorial[i] = factorial[i-1] * i;
        }

        unordered_set<string>visited;
        ll ans = 0ll;

        ll base = pow(10,(n-1)/2);
        for(ll i = base; i < base * 10;i++) {
            string first = to_string(i);
            string second = first;
            reverse(second.begin(),second.end());
            first = first + second.substr(n % 2);

            ll num = stoll(first);
            if(num % k != 0) continue;

            string temp = first;
            sort(temp.begin(),temp.end());
            if(visited.find(temp) != visited.end()) {
                continue;
            }
            visited.insert(temp);

            vector<int>freq(10);
            for(int i = 0;i < temp.size();i++) {
                freq[temp[i] - '0']++;
            }

            ll count = (n - freq[0]) * factorial[n-1];
            for(int i = 0;i < freq.size();i++) {
                count /= factorial[freq[i]];
            }

            ans += count;
        }
        return ans;
    }
};
