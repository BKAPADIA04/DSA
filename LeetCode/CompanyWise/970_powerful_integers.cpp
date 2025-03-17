#define ll long long
class Solution {
public:

    unordered_map<int,int>umap;
    void check(vector<vector<int>>&dp,int x,int y,int i,int j,int bound,vector<int>&ans) {
        int num = int((ll)pow(x,i) + (ll)pow(y,j));
        if(num > bound) {
            return;
        }
        else {
            if(umap.find(num) == umap.end()) {
                umap[num] = 1;
                ans.push_back(num);
            }
        }
        if(i > 100 || j > 100) return;
        if(dp[i][j]) return;
        dp[i][j] = 1;
        check(dp,x,y,i+1,j,bound,ans);
        check(dp,x,y,i,j+1,bound,ans);
    }

    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>ans;
        vector<vector<int>>dp(101,vector<int>(101,0));
        check(dp,x,y,0,0,bound,ans);
        return ans;
    }
};
