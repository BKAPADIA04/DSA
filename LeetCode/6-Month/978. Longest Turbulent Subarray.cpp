class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        vector<int>dpI(n,1);
        vector<int>dpD(n,1);

        for(int i = 1;i < n;i++) {
            if(nums[i] > nums[i-1]) {
                dpI[i] = max(dpI[i], dpD[i-1] + 1);
            }
            else if(nums[i] < nums[i-1]) {
                dpD[i] = max(dpD[i], dpI[i-1] + 1);
            }
        }

        int maxiI = *max_element(dpI.begin(), dpI.end());
        int maxiD = *max_element(dpD.begin(), dpD.end());

        return max(maxiI, maxiD);
    }
};
