class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bound) {
        int n = original.size(); int ans = INT_MAX;
        int low = bound[0][0]; int high = bound[0][1];
        for(int i = 1;i < n;i++) {
            int diff = original[i] - original[i-1];
            low += diff;
            high += diff;

            low = max(low,bound[i][0]);
            high = min(high,bound[i][1]);

            if(high - low + 1 < 0) return 0;

            ans = min(ans,high - low + 1);
        }
        return ans;
    }
};
