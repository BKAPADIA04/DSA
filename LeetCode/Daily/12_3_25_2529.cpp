class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int greater =  n - (upper_bound(nums.begin(),nums.end(),0) - nums.begin());
        int smaller = lower_bound(nums.begin(),nums.end(),0) - nums.begin();

        // cout << greater << " " << smaller << endl;
        return max(greater,smaller);
    }
};
