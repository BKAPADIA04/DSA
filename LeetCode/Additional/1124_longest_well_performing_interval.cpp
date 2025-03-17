class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int>nums;
        for(int i = 0;i < n;i++) {
            if(hours[i] > 8) nums.push_back(1);
            else nums.push_back(-1);
        }

        int maxi = 0; int preSum = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i < n;i++) {
            preSum += nums[i];
            if(preSum > 0) maxi = (i + 1);
            else {
                if(mp.find(preSum-1) != mp.end()) {
                    maxi = max(maxi,i - mp[preSum-1]);
                }
            }
            if(mp.find(preSum) == mp.end()) {
                mp[preSum] = i;
            }
        }
        return maxi;
    }
};
