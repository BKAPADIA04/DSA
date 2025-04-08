class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>freq(110);
        bool flag = true;
        for(int i = 0;i < nums.size();i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > 1) flag = false;
        }
        if(flag) return 0;

        int i = 0;
        int ans = 0;
        while(i < nums.size()) {
            ans++;
            freq[nums[i]]--; i++;
            if(i < nums.size()) {
                freq[nums[i]]--; i++;
            }
            
            if(i < nums.size()) {
                freq[nums[i]]--; i++;
            }

            flag = true;
            for(int i = 0;i < freq.size();i++) {
                if(freq[i] > 1) flag = false;
            }

            if(flag) return ans;
        }
        return ans;
    }
};

/*class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> seen(128);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (seen[nums[i]]) {
                return i / 3 + 1;
            }
            seen[nums[i]] = true;
        }
        return 0;
    }
};*/
