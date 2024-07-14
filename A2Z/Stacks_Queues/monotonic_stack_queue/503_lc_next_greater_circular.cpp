#include <bits/stdc++.h>
using namespace std;

void print(stack<int>st) {
    stack<int>temp = st;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int>st;
    int n = nums.size();
    vector<int>answer(n,-1);

    for(int i = 2*n - 1;i >= 0;i--) {
        while(!st.empty() && (st.top() <= nums[i%n])) {
            st.pop();
        } 
        
        if(i < n && !st.empty()) {answer[i] = st.top(); }
        st.push(nums[i%n]);
        // cout << i << endl;
        // print(st);
    }  
    return answer;
}

int main() {
    // vector<int>nums = {1,2,1};
    vector<int>nums = {1,2,3,4,3};
    vector<int>answer = nextGreaterElements(nums);
    for(int i:answer) cout << i << " ";
    cout << endl;
}   