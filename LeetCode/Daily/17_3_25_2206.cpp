class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(510,0);
        for(int i = 0;i < n;i++) {
            freq[nums[i]]++;
        }

        for(int i = 0;i < freq.size();i++) {
            if(freq[i] & 1) return false;
        }
        return true;
    }
};
