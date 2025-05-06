class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // The core logic behind the encoding using bitwise NOT (~) is to store two values in a single array element without losing the original data, since we aren't allowed to use extra space.
        for(int i = 0;i < n;i++) {
            int x = nums[i];
            if(x < 0) continue;
            int curr = i;
            while(nums[curr] != i) {
                int nxt = nums[curr];
                nums[curr] = ~nums[nxt];
                curr = nxt;
            }
            nums[curr] = ~x;
        }

        for (int i = 0; i < n; i++) {
            nums[i] = ~nums[i];
        }
        return nums;
    }
};
