class Solution {
public:

    int mod = 1e9 + 7;

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int maxi = 2 * nums[i];
            int cnt = 0;
            while((1 << cnt) <= maxi) {
                int number = (1 << cnt);
                if(number >= nums[i]) {
                    int req = number - nums[i];
                    if(mp.find(req) != mp.end()) {
                        ans = (ans + mp[req]) % mod;
                    }
                }
                cnt++;
            }
            mp[nums[i]]++;
        }

        return ans;
    }
};
