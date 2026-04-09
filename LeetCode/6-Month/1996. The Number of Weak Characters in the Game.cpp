class Solution {
public:

    static bool comparator(vector<int>&a, vector<int>&b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comparator);
        int ans = 0;

        int maxi = nums[n-1][1];
        for(int i = n - 2;i >= 0;i--) {
            if(maxi > nums[i][1]) {
                ans++;
            }

            maxi = max(maxi, nums[i][1]);
        }

        return ans;
    }
};
