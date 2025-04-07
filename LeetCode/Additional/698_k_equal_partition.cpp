class Solution {
public:

    int target;

    int check(vector<int>&dp, vector<int>&nums, int index,vector<int>&subsetSum) {
        if(index == nums.size()) {
            return true;
        }

        bool ans = false;
        for(int i = 0;i < subsetSum.size();i++) {
            if(subsetSum[i] + nums[index] > target) continue; 
            if(i > 0 && subsetSum[i] == subsetSum[i-1]) continue;
            subsetSum[i] = subsetSum[i] + nums[index];
            ans = ans || check(dp,nums,index+1,subsetSum);
            subsetSum[i] = subsetSum[i] - nums[index];
        }

        return ans;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % k > 0) return false;
        else {
            vector<int>subsetSum(k,0);
            target = sum / k;
            sort(nums.begin(), nums.end(), greater<int>());
            vector<int>dp;
            return check(dp,nums,0,subsetSum);
        }
        return false;
    }
};
