class Solution {
public:

    vector<vector<int>>dp;
    int check(string &source, string &pattern, vector<int>& indices, int i, int j) {
        if(i < j) return -1;
        if(i < 0) return 0;
        if(j < 0) {
            return check(source,pattern,indices,i-1,-1) + indices[i];
        }

        if(dp[i][j] != -2) return dp[i][j];

        int remove = -1; int notRemove = -1;
        if(source[i] == pattern[j]) {
            notRemove = check(source,pattern,indices,i-1,j-1);
        }
        else {
            notRemove = check(source,pattern,indices,i-1,j);
        }

        if(indices[i]) {
            int temp = check(source,pattern,indices,i-1,j);
            if(temp != -1) remove = 1 + temp;
        }
        // cout << i << " " << j << " " << remove << " " << notRemove << endl;
        return dp[i][j] = max(remove,notRemove);
        
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        vector<int>indices(source.size(),0);
        for(int it:targetIndices) indices[it] = 1;
        dp.assign(source.size(),vector<int>(pattern.size(),-2));
        return check(source,pattern,indices,source.size()-1,pattern.size()-1);
    }
};
