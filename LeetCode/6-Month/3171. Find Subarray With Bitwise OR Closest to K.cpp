class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        unordered_set<int>s;

        for(int i : nums) {
            unordered_set<int>s2;
            for(int j : s) {
                int x = i | j;
                s2.insert(x);
                ans = min(ans, abs(x - k));
            }
            s2.insert(i);
            ans = min(ans, abs(i - k));
            s = s2;
        }
        return ans;
    }
};
