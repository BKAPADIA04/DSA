class Solution {
public:

    int zero; int one; int limit;
    vector<vector<vector<int>>>dp;
    int mod = 1e9 + 7;

    int check(int zeroes, int ones, int option) {
        if(zeroes == 0 && ones == 0) return 1;
        if(zeroes < 0 || ones < 0) return 0;

        if(dp[zeroes][ones][option + 1] != -1) return dp[zeroes][ones][option + 1];

        int z = 0; int o = 0;
        for(int i = 1;i <= limit;i++) {
            if(option == -1) {
                z = (z + check(zeroes - i,ones,1)) % mod;
                o = (o + check(zeroes, ones - i,0)) % mod;
            }
            if(option == 0) {
                z = (z + check(zeroes - i,ones,1)) % mod;
            }
            if(option == 1) {
                o = (o + check(zeroes, ones - i,0)) % mod;
            }
        }
        return dp[zeroes][ones][option + 1] = (z + o) % mod;

    }

    int numberOfStableArrays(int zero_, int one_, int limit_) {
        zero = zero_;
        one = one_;
        limit = limit_;
        dp = vector<vector<vector<int>>>(zero + 2,vector<vector<int>>(one + 2,vector<int>(3,-1)));
        return check(zero,one,-1);
    }
};
