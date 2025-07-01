class Solution {
public:

    vector<int>primes;
    int mod = 1e9 + 7;
    vector<vector<int>>dp;

    int getMask(int num) {
        int mask = 0;
        int temp = num;
        for(int i = 0;i < primes.size();i++) {
            int div = primes[i];
            if(temp % div == 0) {
                int counter = 0;
                while(temp % div == 0 && temp != 1) {
                    temp/=div;
                    counter++;
                }
                if(counter > 1) return -1;
                if(counter == 1) mask |= (1 << i);
            }
        }
        return mask;
    }

    int check(int index, int bitMask,vector<int>&nums) {
        if(index == nums.size()) return 1;

        if(dp[index][bitMask] != -1) return dp[index][bitMask];

        int eleMask = getMask(nums[index]);

        int opt1 = check(index + 1, bitMask,nums) % mod;
        int opt2 = 0;
        if(eleMask != -1 && ((bitMask & eleMask) == 0)) {
            opt2 = check(index + 1, bitMask | eleMask,nums) % mod;
        }
        return dp[index][bitMask] = (opt1 + opt2) % mod;
    }

    int squareFreeSubsets(vector<int>& nums) {
        primes = {2,3,5,7,11,13,17,19,23,29};

        dp = vector<vector<int>>(nums.size(),vector<int>(1 << 11,-1));
        return (check(0,0,nums) - 1 + mod) % mod;
    }
};
