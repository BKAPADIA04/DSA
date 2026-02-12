class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k) return false;
        int grps = n / k;

        sort(nums.begin(), nums.end());
        vector<int>smallest(grps, INT_MAX);
        vector<int>sz(grps, 0);

        int j = 0;

        for(int i = 0;i < n;i++) {
            if(smallest[j] == nums[i]) return false;
            smallest[j] = nums[i];
            sz[j]++;
            j = (j + 1) % grps;
        }

        return count(sz.begin(),sz.end(), k) == grps;

    }
};

/*class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n= nums.size();
        if(n%k!=0){
            return 0;
        }
        int occ = n/k;
        vector<int>mpp(1e5+1,0);
        for(int i=0;i<n;i++){ 
            mpp[nums[i]]++;
            if(mpp[nums[i]]>occ){
                return false;
            }
        }
        return true;

    }
};*/
