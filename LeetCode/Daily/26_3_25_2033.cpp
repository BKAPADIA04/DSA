class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>nums;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        int ans = 0;
        int median = nums[sz/2];
        for(int i = 0;i < nums.size();i++) {
            if(abs(median - nums[i]) % x == 0) ans += (abs(median - nums[i]))/x;
            else return -1;
        }
        // if(sz & 1) {
        //     int median = nums[sz/2];
        //     for(int i = 0;i < nums.size();i++) {
        //         if(abs(median - nums[i]) % x == 0) ans += (abs(median - nums[i]))/x;
        //         else return -1;
        //     }
        // }
        // else {
        //     int ans1 = 0; int ans2 = 0;
        //     int median1 = nums[sz/2-1];
        //     for(int i = 0;i < nums.size();i++) {
        //         if(abs(median1 - nums[i]) % x == 0) ans1 += (abs(median1 - nums[i]))/x;
        //         else { ans1 = -1; break;}
        //     }
        //     int median2 = nums[sz/2];
        //     for(int i = 0;i < nums.size();i++) {
        //         if(abs(median2 - nums[i]) % x == 0) ans2 += (abs(median2 - nums[i]))/x;
        //         else { ans2 = -1; break;}
        //     }
        //     if(ans1 != -1 && ans2 != -1) {
        //         ans = min(ans1,ans2);
        //         return ans;
        //     }
        //     if(ans1 == -1) return ans2;
        //     if(ans2 == -1) return ans1;
        // }
        return ans;
    }
};
