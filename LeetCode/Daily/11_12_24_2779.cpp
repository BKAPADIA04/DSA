class Solution {
public:
    void print(vector<int>&nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>sweep(nums[n-1] + k + 2,0);
        for(int i = 0;i < n;i++) {
            int low = nums[i] - k;
            int high = nums[i] + k;
            if(low < 0) low = 0;
            sweep[low]++;
            sweep[high+1]--;
        }
        int answer = sweep[0];
        for(int i = 1; i < sweep.size();i++) {
            sweep[i] = sweep[i] + sweep[i-1];
            answer = max(answer,sweep[i]);
        }
        print(sweep);
        return answer;
    }
};