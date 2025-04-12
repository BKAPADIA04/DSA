class Solution {
public:

    vector<int>dp;

    int check(int index,int d,vector<int>&nums,int n,vector<int>&visited) {
        if(dp[index] != -1) return dp[index];

        int ans = 0;
        int temp1 = 0; int temp2 = 0;

        visited[index] = 1;
        for(int i = 1;i <= d;i++) {
            int newX = index + i;
            if(newX < n && nums[newX] >= nums[index]) break;
            if(newX < n && !visited[newX]) {
                temp1 = max(temp1,1 + check(newX,d,nums,n,visited));
            }
        }

        for(int i = 1;i <= d;i++) {
            int newX = index - i;
            if(newX >= 0 && nums[newX] >= nums[index]) break;
            if(newX >= 0 && !visited[newX]) {
                temp2 = max(temp2,1 + check(newX,d,nums,n,visited));
            }
        }

        visited[index] = 0;

        ans = max(temp1, temp2);

        return dp[index] = ans;
    }


    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        dp = vector<int>(arr.size(),-1);
        for(int i = 0;i < arr.size();i++) {
            vector<int>visited(arr.size(),0);
            ans = max(ans,1 + check(i,d,arr,arr.size(),visited));
        }
        return ans;
    }
};
