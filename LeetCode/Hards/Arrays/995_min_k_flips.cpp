class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>flipped(n,0);
        int ans = 0; int times = 0;
        for(int i = 0;i < n;i++) {
            if(i >= k) {
                times -= flipped[i-k];
            }

            if((nums[i] && times % 2 == 1) || (!nums[i] && times % 2 == 0)) {
                if(n - i < k) return -1;
                ans++;
                times++;
                flipped[i]++;
            }
        }
        return ans;
    }
};
