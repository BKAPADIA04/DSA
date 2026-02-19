class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int>nums;
        int curr = 1; int index = 0;
        for(int i = 1;i < n;i++) {
            if(s[i] != s[index]) {
                nums.push_back(curr);
                curr = 1; index = i;
            }
            else {
                curr++;
            }
        }
        nums.push_back(curr);

        int ans = 0;
        for(int i = 1;i < nums.size();i++) {
            ans += min(nums[i], nums[i-1]);
        }
        return ans;
    }

};
