class Solution {
public:
    int minimumOR(vector<vector<int>>& nums) {
        int ans = (1ll << 31) - 1;
        for(int bit = 30; bit >= 0;bit--) {
            int reqAns = ans ^ (1 << bit);
            bool flag = true;
            for(auto row : nums) {
                bool check = false;
                for(int num : row) {
                    if((reqAns | num) == reqAns) check = true;
                }
                if(!check) flag = false;
            }
            if(!flag) continue;
            ans = reqAns;
        }
        return ans;
    }
};
