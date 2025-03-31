class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<int>preMax(n,-1);
        vector<int>preIndices(n,-1); int maxi = nums[0]; int maxIndex = 0;
        for(int i = indexDifference;i < n;i++) {
            if(nums[i - indexDifference] >= maxi) {
                maxi = nums[i - indexDifference];
                maxIndex = i - indexDifference;
            }
            preMax[i] = maxi;
            preIndices[i] = maxIndex;
        }
    
        vector<int>sufMax(n,-1);
        vector<int>sufIndices(n,-1);
        maxi = nums[n - 1];
        maxIndex = n - 1;
        for(int i = n - 1 - indexDifference; i >= 0;i--) {
            if(nums[i + indexDifference] >= maxi) {
                maxi = nums[i + indexDifference];
                maxIndex = i + indexDifference;
            }
            sufMax[i] = maxi;
            sufIndices[i] = maxIndex;
        }

        for(int i = 0;i < n;i++) {
            if(preIndices[i] != -1 && (abs(nums[preIndices[i]] - nums[i]) >= valueDifference)) {
                return {i,preIndices[i]};
            }
            if(sufIndices[i] != -1 && (abs(nums[sufIndices[i]] - nums[i]) >= valueDifference)) {
                return {i,sufIndices[i]};
            }
        }

        return {-1,-1};
    }
};
