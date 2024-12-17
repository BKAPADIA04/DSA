class Solution {
public:
    int getFruits(int leftSteps, int rightSteps,int startPos,int maxRight,vector<int>&prefix) {
        int l = max(0, startPos - leftSteps);
        int r = min(maxRight, startPos + rightSteps);
        return prefix[r + 1] - prefix[l];
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxRight = max(startPos, fruits.back()[0]);
        int ans = 0;
        vector<int> amounts(1 + maxRight);
        vector<int> prefix(2 + maxRight);

        for(int i = 0;i < fruits.size();i++) {
            amounts[fruits[i][0]] = fruits[i][1];
        }

        partial_sum(amounts.begin(), amounts.end(), prefix.begin() + 1);

        int maxRightSteps = min(maxRight - startPos, k);
        for (int rightSteps = 0; rightSteps <= maxRightSteps; ++rightSteps) {
            int leftSteps = max(0, k - 2 * rightSteps);  // Turn left
            ans = max(ans, getFruits(leftSteps, rightSteps,startPos,maxRight,prefix));
        }


        int maxLeftSteps = min(startPos, k);
        for (int leftSteps = 0; leftSteps <= maxLeftSteps; ++leftSteps) {
            int rightSteps = max(0, k - 2 * leftSteps);  // Turn right
            ans = max(ans, getFruits(leftSteps, rightSteps,startPos,maxRight,prefix));
        }

    return ans;
    }
};