class Solution {
public:

    void print(vector<int>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }

    int minOperations(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        for(int i = 0;i < nums.size();i++) {
            int ele = nums[i];
            for(int j = 0;j <= 31;j++) {
                if(((1 << j) & ele) > 0) bits[j]++;
                bits[j] %= 2;
            }
        }
        int ans = 0;
        vector<int>req(32,0);
        for(int j = 0;j <= 31;j++) {
            if(((1 << j) & k) > 0) req[j]++;
            req[j] %= 2;
            ans += (bits[j] != req[j]);
        }

        // int ans = 0;
        // for(int i = 0; i <= 31;i++) {
        //     ans += (bits[i] != req[i]);
        // }
        
        return ans;
    }
};
