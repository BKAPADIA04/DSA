typedef long long ll;
class Solution {
public:
    ll n;
    int req2, req3, req5;
    vector<int> nums;
    
    map<vector<int>, ll> memo;

    ll solve(int i, int c2, int c3, int c5) {
        
        if (i == n) {
            return (c2 == req2 && c3 == req3 && c5 == req5) ? 1 : 0;
        }

        
        vector<int> state = {i, c2, c3, c5};
        if (memo.count(state)) return memo[state];

        
        int n2 = 0, n3 = 0, n5 = 0;
        int val = nums[i];
        if (val > 0) {
            int temp = val;
            while (temp % 2 == 0) { n2++; temp /= 2; }
            while (temp % 3 == 0) { n3++; temp /= 3; }
            while (temp % 5 == 0) { n5++; temp /= 5; }
            
        }

        ll ans = 0;
        
        ans += solve(i + 1, c2 + n2, c3 + n3, c5 + n5);
        
        ans += solve(i + 1, c2 - n2, c3 - n3, c5 - n5);
        
        ans += solve(i + 1, c2, c3, c5);

        return memo[state] = ans;
    }

    int countSequences(vector<int>& nums, long long k) {
        long long temp = k; 
        this->nums = nums;
        this->n = nums.size();
        this->memo.clear();
        
        req2 = 0, req3 = 0, req5 = 0;
        ll tempK = temp;

        if (tempK > 0) {
            while (tempK % 2 == 0) { req2++; tempK /= 2; }
            while (tempK % 3 == 0) { req3++; tempK /= 3; }
            while (tempK % 5 == 0) { req5++; tempK /= 5; }
        }

        
        if (tempK != 1) return 0; 

        return (int)solve(0, 0, 0, 0);
    }
};
