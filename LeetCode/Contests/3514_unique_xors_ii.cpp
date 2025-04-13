class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> poss(3001, false);
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                poss[nums[i] ^ nums[j]] = true;
            }
        }
        
        vector<bool> newposs(3001,false);
        for(int i = 0; i <= 3000; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(((i ^ nums[j]) <= 3000) && poss[i ^ nums[j]]) {newposs[i] = true; break;}
            }
        }
        
        return count(newposs.begin(), newposs.end(), true);
    }
};
