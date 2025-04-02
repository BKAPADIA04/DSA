#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>preMax(n,0); vector<int>sufMax(n,0);
        preMax[0] = nums[0];
        for(int i = 1;i < n;i++) {
            preMax[i] = max(preMax[i-1],nums[i]);
        }
        sufMax[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--) {
            sufMax[i] = max(sufMax[i+1],nums[i]);
        }

        ll ans = 0;
        for(int i = 1;i < n - 1;i++) {
            if(nums[i] < preMax[i]) {
                ans = max(ans,(ll)(preMax[i - 1] - nums[i]) * sufMax[i + 1]);
            } 
        }
        return ans;
    }
};
