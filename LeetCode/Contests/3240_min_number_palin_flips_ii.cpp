class Solution {
public:

    int check(vector<vector<int>>&grid,int row,int col,int n,int m) {
        int ans = 0;
        int extraOnes = 0;
        int diffPairs = 0;
        for(int i = 0;i <= row;i++) {
            for(int j = 0;j <= col;j++) {
                map<pair<int,int>,int>mp;
                int costOnes = 0; int costZeros = 0;
                if(grid[i][j]) costZeros++;
                else costOnes++;
                mp[{i,j}]++;

                // row check
                int newI = n - 1 - i;
                if(mp.find({newI,j}) == mp.end()) {
                    if(grid[newI][j]) costZeros++;
                    else costOnes++;
                    mp[{newI,j}]++;
                }
                // col check
                int newJ = m - 1 - j;
                if(mp.find({i,newJ}) == mp.end()) {
                    if(grid[i][newJ]) costZeros++;
                    else costOnes++;
                    mp[{i,newJ}]++;
                }
                // diagonal check
                if(mp.find({newI,newJ}) == mp.end()) {
                    if(grid[newI][newJ]) costZeros++;
                    else costOnes++;
                    mp[{newI,newJ}]++;
                }

                if(mp.size() == 4) {
                    ans += min(costOnes,costZeros);
                }
                else if(mp.size() == 2) {
                    if(costZeros % 2 == 0) {
                        extraOnes += costZeros;
                    }
                    diffPairs += min(costOnes,costZeros);
                }
                else if(mp.size() == 1) {
                    if(grid[i][j]) ans++;
                }

            }
        }
        extraOnes %= 4;
        if(diffPairs > 0) extraOnes = 0;
        ans += diffPairs;
        ans += extraOnes;
        return ans;
    }

    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int row = (n - 1)/2;
        int col = (m - 1)/2;

        return check(grid,row,col,n,m);
    }
};


