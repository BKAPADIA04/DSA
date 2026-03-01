class Solution {
public:

    vector<int>check(vector<int>& nums, bool odd) {
        int ans = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0;i < nums.size();i++) {
            if((((abs(nums[i]) % 2) == 0) && odd) || (((abs(nums[i]) % 2) == 1) && !odd)) {
                ans++;
                maxi = max(maxi, nums[i] - 1);
                mini = min(mini, nums[i] + 1);
            }
            else {
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
            }

            odd = !odd;
        }

        return {ans, maxi - mini};
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0,0};

        unordered_set<int>st(nums.begin(),nums.end());
        if(st.size() == 1) {
            return {n/2,1};
        }

        vector<int>oddFirst = check(nums,true);
        vector<int>evenFirst = check(nums, false);

        // cout << oddFirst[0] << " " << oddFirst[1] << endl;
        // cout << evenFirst[0] << " " << evenFirst[1] << endl;

        if(oddFirst[0] == evenFirst[0]) {
            if(oddFirst[1] < evenFirst[1]) return oddFirst;
            else return evenFirst;
        }

        if(oddFirst[0] < evenFirst[0]) {
            return oddFirst;
        }
        return evenFirst;
    }
};
