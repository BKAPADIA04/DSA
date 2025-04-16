class Solution {
public:
    int dp[10][1<<10][2][2];
    int solve(string &nums,int i=0,int mask=0,bool rep=0,int tight=1){
        if(i>=nums.size())
            return rep and mask!=0;
        if(dp[i][mask][rep][tight]!=-1)
            return dp[i][mask][rep][tight];
        int ub=tight?(nums[i]-'0'):9;
        int ans=0;
        for(int j=0;j<=ub;j++){
            if(mask==0 and j==0 )
                ans+=solve(nums,i+1,mask,rep,tight&(j==ub));
            else if(mask&(1<<j))
                ans+=solve(nums,i+1,mask,true,tight&(j==ub));
            else
                ans+=solve(nums,i+1,mask|(1<<j),rep,tight&(j==ub));
        }
        return dp[i][mask][rep][tight]=ans;
    }
    int numDupDigitsAtMostN(int n) {
        string nums=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(nums);
    }
};
