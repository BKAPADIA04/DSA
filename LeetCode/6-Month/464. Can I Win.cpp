class Solution {
public:

    int maxChoosableInteger, desiredTotal;
    map<pair<int,int>, bool> dp;

    bool check(int bitMask, int rem) {
        if(rem <= 0) return false; 
        if(bitMask == 0) return false;

        if(dp.find({bitMask, rem}) != dp.end()) return dp[{bitMask, rem}];
        
        for(int i = 1;i <= maxChoosableInteger;i++) {
            if(bitMask & (1 << (i - 1))) {
                if(!check(bitMask ^ (1 << (i - 1)), rem - i)) return dp[{bitMask, rem}] = true;
            }
        }

        return dp[{bitMask, rem}] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        this->maxChoosableInteger = maxChoosableInteger;
        this->desiredTotal = desiredTotal;

        if(desiredTotal == 0) return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1)/2;
        if(sum < desiredTotal) return false;

        int bitMask = (1 << maxChoosableInteger) - 1;

        return check(bitMask, desiredTotal);
    }
};
