#include <bits/stdc++.h>
using namespace std;

// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     queue<int>q;
//     vector<int>answer;

//     for(int i = 0;i < nums2.size();i++) q.push(nums2[i]);
//     int last = q.back();

//     for(int i = 0;i < nums1.size();i++) {
//         while(nums1[i] != q.front()) {
//             q.push(q.front());
//             q.pop();
//         }
//         q.push(q.front());
//         q.pop();
//         while(q.front() != last && q.front() <= nums1[i]) {
//             // answer.push_back(q.front());
//             q.push(q.front());
//             q.pop();
//         }
//         if(q.front() != last) { answer.push_back(q.front());q.push(q.front());q.pop(); }
//         if(q.front() == last && last > nums1[i]) { answer.push_back(q.front());q.push(q.front());q.pop();}

//     }   
// }


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>answer;
    stack<int>st;
    for(int i = nums2.size()-1;i >= 0;i--) {
        if(st.empty()) {
            answer[nums2[i]] = -1;
        }
        else {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if(st.empty()) {
                answer[nums2[i]] = -1;
            }
            else {
                answer[nums2[i]] = st.top();
            }
        }
        st.push(nums2[i]);
    }
    vector<int>ans(nums1.size(),0);
    for(int i = 0;i < nums1.size();i++) {
        ans[i] = answer[nums1[i]];
    }
    return ans;
}

int main() {
    vector<int>nums1 = {1,2,3,4,5};
    vector<int>nums2 = {5,4,3,2,1};
    // vector<int>nums1 = {2,4};
    // vector<int>nums2 = {1,2,3,4};
    vector<int>answer = nextGreaterElement(nums1,nums2);
    for(int i:answer) cout << i << " ";
    cout << endl;
}