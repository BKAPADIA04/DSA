class Solution {
public:

    int N;

    vector<vector<vector<int>>>dp;

    int check(vector<int>&piles, int index, int m, int chance) {
        if(index >= N) return 0;
        
        if(dp[index][m][chance] != -1) return dp[index][m][chance];
        int ans = (chance == 1) ? -1 : INT_MAX;
        int sum = 0;
        for(int x = 1; x <= min(2 * m, N - index); x++) {
            sum += piles[index + x - 1];

            if(chance == 1) {
                ans = max(ans, sum + check(piles, index + x, max(m,x),1 - chance));
            }
            else {
                ans = min(ans, check(piles, index + x, max(m,x),1 - chance));
            }
        }
        return dp[index][m][chance] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(N + 1,vector<int>(2,-1)));
        return check(piles,0,1,1);
    }
};
// class Solution {
// public:
//     int N;
//     vector<vector<int>> dp;

//     int check(vector<int>& piles, int i, int M) {
//         if (i >= N) return 0;
//         if (dp[i][M] != -1) return dp[i][M];

//         int maxStones = 0, sum = 0;
//         for (int x = 1; x <= min(2 * M, N - i); x++) {
//             sum += piles[i + x - 1];
//             // Player 2 will play next → minimize what player 1 can get in next round
//             int next = check(piles, i + x, max(M, x));
//             maxStones = max(maxStones, sum + (totalSum(piles, i + x) - next));
//         }

//         return dp[i][M] = maxStones;
//     }

//     int totalSum(vector<int>& piles, int start) {
//         int sum = 0;
//         for (int i = start; i < piles.size(); ++i) sum += piles[i];
//         return sum;
//     }

//     int stoneGameII(vector<int>& piles) {
//         N = piles.size();
//         dp = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
//         return check(piles, 0, 1);
//     }
// };
