class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int>nums(n,0);
        vector<int>answer(n,0);
        vector<int>maximum(n,-1); int maxi = -1;
        for(int i = 0;i < n;i++) {
            nums[i] = lower_bound(prizePositions.begin(),prizePositions.end(),prizePositions[i] - k) - prizePositions.begin();
            answer[i] = i - nums[i] + 1;
            maxi = max(maxi,answer[i]);
            maximum[i] = maxi;
        }
        // cout << n << endl;

        int ans = answer[0];
        // cout << ans << endl;
        for(int i = 1;i < n;i++) {
            if(nums[i] - 1 >= 0) ans = max(ans,answer[i] + maximum[nums[i]-1]);
            else ans = i + 1;
            // cout << ans << endl;
        }
        // for(auto it:nums) cout << it << " ";
        // cout << endl;
        // for(auto it:answer) cout << it << " ";
        // cout << endl;
        // for(auto it:maximum) cout << it << " ";
        // cout << endl;
        return ans;
    }
};
