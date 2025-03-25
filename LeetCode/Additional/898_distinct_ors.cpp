class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s; int curr = 0; 
        for(int i = 0;i < n;i++) {
            curr |= nums[i]; int temp = 0;
            for(int j = i;j >= 0;j--) {
                temp |= nums[j];
                s.insert(temp);
                if(curr == temp) break;
            }
        }
        return s.size();
    }
};
