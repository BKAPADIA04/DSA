class Solution {
public:

    vector<int>nseF(vector<int>&nums) {
        int n = nums.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i = n - 1;i >= 0;i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }   
        return ans;
    }

    vector<int>pseF(vector<int>&nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i = 0;i < n;i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }   
        return ans;
    }



    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int>nse = nseF(nums);
        
        vector<int>pse = pseF(nums);
        
        int ans = -1;
        for(int i = 0;i < n;i++) {
            double tempo = (nse[i] - 1) - (pse[i] + 1) + 1;
            double check = threshold/tempo;
            if(nums[i] * 1.0 > check) return (int)tempo;
        }
        return -1;
    }
};
