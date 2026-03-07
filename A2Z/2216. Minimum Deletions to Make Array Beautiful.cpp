class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int deletions = 0;
        
        for(int i = 0;i < n;) {
            if((i - deletions) % 2 == 0) {
                int j = i + 1;
                while(j < n && nums[j] == nums[i]) {
                    j++;
                    deletions++;
                }
                i = j;
            }
            else {
                i++;
            }
        }
        return ((n - deletions) & 1) ? deletions + 1 : deletions;
    }
};
