class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int leftOnes = 0; int rightOnes = 0;
        int ones = 0; int maxOnes = 0; int zeroSegments = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] == '0') {
                rightOnes++;
            }
            else {
                ones++;
                maxOnes = max(maxOnes, leftOnes + rightOnes);
                if(rightOnes != 0) {
                    leftOnes = rightOnes; 
                    zeroSegments++;
                } 
                rightOnes = 0;
            }
        }
        if(rightOnes != 0) zeroSegments++;
        maxOnes = max(maxOnes, leftOnes + rightOnes);
        if(zeroSegments > 1) {
            return ones + maxOnes;
        }
        return ones;
    }
};
