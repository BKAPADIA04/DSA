#define ll long long
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        ll ans = 0ll;
        for(int i = 0;i < n;i++) {
            while(!st.empty() && nums[i] > nums[st.top()]) {
                st.pop();
                if(st.size() > 0) ans++;
            }
            st.push(i);
        }
        return ans;
    }
};
