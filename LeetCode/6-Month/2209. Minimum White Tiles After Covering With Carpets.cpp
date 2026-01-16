class Solution {
public:

    vector<int>suff;
    int n;
    vector<vector<int>>dp;

    int check(string &floor, int i, int c, int len) {
        if(i >= n) return 0;
        if(c <= 0) return suff[i];

        if(dp[i][c] != -1) return dp[i][c];

        int isWhite = 0;
        if(floor[i] == '1') isWhite = 1;

        int opt1 = isWhite + check(floor, i + 1, c, len);
        int opt2 = check(floor, i + len, c - 1, len);

        return dp[i][c] = min(opt1,opt2);
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        n = floor.size();
        suff = vector<int>(n,0);
        for(int i = n - 1;i >= 0;i--) {
            int temp = 0;
            if(floor[i] == '1') temp = 1;
            suff[i] += temp;
            if(i != n - 1) suff[i] += suff[i+1];
        }

        // for(auto it : suff) cout << it << " ";
        dp = vector<vector<int>>(n,vector<int>(numCarpets + 1,-1));
        // for(auto it:dp) {
        //     for(auto it1:it) cout << it1 << endl;
        // }
        return check(floor, 0, numCarpets,carpetLen);
    }
};
