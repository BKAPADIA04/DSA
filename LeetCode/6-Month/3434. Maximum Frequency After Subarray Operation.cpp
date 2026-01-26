class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int kCount = count(nums.begin(),nums.end(),k);
        int maxi = 0;

        for(int i = 1;i <= 50;i++) {
            if(i == k) continue;
            int curr = 0; int maxiCur = 0;
            for(int num : nums) {
                curr += (num == i ? 1 : (num == k ? -1 : 0));
                curr = max(0,curr);
                maxiCur = max(maxiCur, curr);
            } 
            maxi = max(maxi, maxiCur);
        }

        return kCount + maxi;
    }
};
