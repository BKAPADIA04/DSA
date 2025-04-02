#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size(); ll maxi = 0ll;
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                for(int k = j + 1;k < n;k++) {
                    ll temp = (ll)(nums[i] - nums[j]) * (ll)nums[k];
                    if(temp > 0) {
                        maxi = max(maxi,temp);
                    }
                }
            }
        }
        return maxi;
    }
};
