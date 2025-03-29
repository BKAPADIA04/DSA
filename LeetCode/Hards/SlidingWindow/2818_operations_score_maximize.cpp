#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;
    
    void print(vector<int>v) {
        for(auto it:v) {
            cout << it << " ";
        }
        cout << endl;
    }

    ll power(ll x, ll n) {
        if(n == 0) return 1;
        ll check = power(x,n/2) % mod;
        ll nums = (check * check) % mod;
        if(n & 1) nums = (x * nums) % mod;
        return nums % mod;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>primeScore(n,0);
        for(int i = 0;i < n;i++) {
            int num = nums[i];
            for(int j = 2;j <= sqrt(num);j++) {
                if(num % j == 0) {
                    primeScore[i]++;

                    while(num % j == 0) num /= j;
                }
            }
            if(num >= 2) primeScore[i]++;
        }
        
        vector<int>prev(n,-1); vector<int>next(n,n);
        stack<int>st;
        for(int i = 0;i < n;i++) {
            while(!st.empty() && primeScore[st.top()] < primeScore[i]) {
                next[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) prev[i] = st.top();
            st.push(i);
        }
        
        vector<ll>noOfSubarrays(n,0);
        for(int i = 0;i < n;i++) {
            noOfSubarrays[i] = (ll)(i - prev[i]) * (ll)(next[i] - i);
        }
        
        priority_queue<pair<ll,ll>>maxHeap;
        for(int i = 0;i < n;i++) {
            maxHeap.push({nums[i],i});
        }
        ll score = 1;
        while(k > 0) {
            ll index = maxHeap.top().second;
            ll number = maxHeap.top().first;
            maxHeap.pop();
            ll available = min((ll)k, noOfSubarrays[index]);
            ll multi = power(number,available) % mod;
            score = (score * multi) % mod;
            k -= available;
        }


        return score;
    }
};
