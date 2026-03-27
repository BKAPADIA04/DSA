class Solution {
public:

    vector<int> rotate(vector<int>nums, int opt, int k) {
        // opt = 0 -> left rotate
        // opt = 1 -> right rotate

        if(opt == 0) {
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
            reverse(nums.begin(), nums.end());
        }
        else {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        }

        return nums;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;

        vector<vector<int>>nums;
        for(int i = 0;i < m;i++) {
            nums.push_back(rotate(mat[i], i & 1,k));
        }

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(nums[i][j] != mat[i][j]) return false;
            }
        }

        return true;
    }
};
