class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>nums(m,vector<int>(n,0));

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(i-1 >= 0) nums[i][j] = nums[i-1][j];
                if(matrix[i][j] == 1) nums[i][j] += 1;
                else nums[i][j] = 0;
            }
        }

        for(int i = 0;i < m;i++) {
            sort(nums[i].rbegin(), nums[i].rend());
        }

        int ans = 0;

        // for(int i = 0;i < m;i++) {
        //     for(int j = 0;j < n;j++) {
        //         cout << nums[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                int temp = nums[i][j] * (j+1);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
