#include <bits/stdc++.h>
using namespace std;

vector<int>prevSmaller(vector<int> &nums) {
    vector<int>answer(nums.size(),-1);
    stack<int>st;
    for(int i = 0;i < nums.size();i++) {
        if(st.empty()) {
            answer[i] = -1;
        }
        else {
            while(!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                answer[i] = -1;
            }
            else {
                answer[i] = st.top();
            }
        }
        st.push(nums[i]);
    }
    return answer;
}

int main() {
    vector<int>nums = {4, 5, 2, 10, 8};
    vector<int>answer = prevSmaller(nums);
    for(int i:answer) cout << i << " ";
    cout << endl;
}