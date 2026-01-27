class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX, mx = INT_MIN;
        unordered_map<int, int> mp;
        for(auto n: nums){
            int r = n % space;                  //evaluate reminder
            mp[r]++;                               // add reminder to map
            if(mx < mp[r])  mx = mp[r];   //keep track of the max count, with same reminder
        }
        for(auto n: nums){  //scan smalest element with same riminder as of mx
            if(mx == mp[n%space])  ans = min(ans, n);
        }
        return ans;
    }
};
