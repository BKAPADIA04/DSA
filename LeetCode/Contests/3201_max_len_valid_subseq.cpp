class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>mod0(n,1);
        vector<int>mod1(n,1);
        mod0[n - 1] = 1; mod1[n - 1] = 1;
        int even = -1; int odd = -1;

        if(nums[n - 1] & 1) odd = n - 1;
        else even = n - 1;

        for(int i = n - 2;i >= 0;i--) {
            if(nums[i] & 1) {
                // mod 0
                if(odd != -1) mod0[i] = max(mod0[i],1 + mod0[odd]);
                odd = i;

                // mod 1
                if(even != -1) mod1[i] = max(mod1[i],1 + mod1[even]);
            }
            else {

                // mod 0
                if(even != -1) mod0[i] = max(mod0[i],1 + mod0[even]);
                even = i;

                // mod1
                if(odd != -1) mod1[i] = max(mod1[i],1 + mod1[odd]);
            }
        }

        // for(auto it : mod0) cout << it << " ";
        // cout << endl;
        
        // for(auto it : mod1) cout << it << " ";
        // cout << endl;
        
        int ans1 = *max_element(mod0.begin(),mod0.end());
        int ans2 = *max_element(mod1.begin(),mod1.end());
        return max(ans1,ans2);
    }
};
