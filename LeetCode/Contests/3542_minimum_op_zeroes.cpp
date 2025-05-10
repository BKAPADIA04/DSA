class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int answer = 0;
        for(int num : nums) {
            while(!st.empty() && st.top() > num) {
                st.pop();
                answer++;
            }
            if(!st.empty() && st.top() == num) continue;
            if(num != 0) st.push(num);
        }
        answer += st.size();
        return answer;
        
    }
};
