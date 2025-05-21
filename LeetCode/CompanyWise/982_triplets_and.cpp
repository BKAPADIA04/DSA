class Solution {
public:

    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>freq(maxi+1);

        int answer = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int andd = nums[i] & nums[j];
                freq[andd]++;
            }
        }

        for(int i = 0;i <= maxi;i++) {
            for(int j = 0;j < n;j++) {
                if((i & nums[j]) == 0) {
                    answer += freq[i];
                }
            }
        }
        return answer;
    }
};
