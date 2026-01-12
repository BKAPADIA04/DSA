class Solution {
public:

    int rec(int ind,int sum,map<pair<int,int>,int>&dp,vector<int>&digits){
        if(ind==digits.size()){
            if(sum==0){
                return dp[{ind,sum}]=0;
            }
            return dp[{ind,sum}]=-1e9;
        }
        else if(dp.find({ind,sum})!=dp.end()){
            return dp[{ind,sum}];
        }
        int p=1+rec(ind+1,(sum+digits[ind])%3,dp,digits);
        int np=rec(ind+1,sum%3,dp,digits);
        return dp[{ind,sum}]=max(p,np);
    }

    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.rbegin(),digits.rend());
        if(digits[0]==0){
            return "0";
        }
        int n=digits.size();
        // vector<vector<int>> dp(n+1,vector<int>(9*n+1,-1));
        map<pair<int,int>,int> dp;
        int ans=rec(0,0,dp,digits);
        string s="";
        int sum=0;
        for(int i=0;i<n;i++){
            if(dp[{i+1,sum%3}]>1+dp[{i+1,(sum+digits[i])%3}]){
                continue;
            }
            else{
                s+=('0'+digits[i]);
                sum+=digits[i];
                sum%=3;
            }
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cnt++;
            }
        }
        if(s.size()==cnt and !s.empty()){
            return "0";
        }
        return s;
    }   
};
