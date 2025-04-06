class Solution {
public:
    int minCost(string colors, vector<int>& nums) {
        int n = colors.size();
        int ans = 0;
        int j = 0; int sum = nums[0]; int maxi = nums[0];
        for(int i = 1;i < n;i++) {
            if(colors[i] == colors[j]) {
                sum += nums[i];
                maxi = max(maxi,nums[i]);
            }
            else {
                ans += (sum - maxi);
                j = i;
                sum = nums[j];
                maxi = nums[j];
            }
        }
        ans += (sum - maxi);
        return ans;
    }
};
