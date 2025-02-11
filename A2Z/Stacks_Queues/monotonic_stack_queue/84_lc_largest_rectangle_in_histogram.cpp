#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int>left(n,0),right(n,0);
    stack<int>st;
    for(int i = 0;i < n;i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) left[i] = 0; 
        else left[i] = st.top() + 1;
        st.push(i);
    }  
    while(!st.empty()) st.pop();    
    for(int i = n-1;i >= 0;i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) right[i] = n - 1; 
        else right[i] = st.top() - 1;
        st.push(i);
    }    
    while(!st.empty()) st.pop();    

    int answer = INT_MIN;
    for(int i = 0;i < n;i++) {
        answer = max(answer,(((right[i] - left[i] + 1) * heights[i])));
    }
    return answer;
}

int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << "The largest area in the histogram is " << largestRectangleArea(heights) << endl; 
  return 0;
}

/*class Solution {
public:

    void print(vector<int>nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    }

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int>left(n),right(n);
    //     stack<int>st;
    //     for(int i = 0;i < n;i++) {
    //         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
    //         if(st.empty()) left[i] = 0;
    //         else left[i] = st.top() + 1; 
    //         st.push(i);
    //     }
    //     while(!st.empty()) st.pop();

    //     for(int i = n-1;i >= 0;i--) {
    //         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
    //         if(st.empty()) right[i] = n - 1;
    //         else right[i] = st.top() - 1; 
    //         st.push(i);
    //     }
    //     while(!st.empty()) st.pop();

    //     int ans = 0;
    //     for(int i = 0;i < n;i++) {
    //         ans = max(ans,(right[i] - left[i] + 1) * heights[i]);
    //     }
    //     // print(left); print(right);
    //     return ans;
    // }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int>st;
        for(int i = 0;i < n;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top(); st.pop(); int nse = i; int pse = st.empty() ? -1 : st.top();

                ans = max(ans,heights[index] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int index = st.top(); st.pop(); int nse = n; int pse = st.empty() ? -1 : st.top();
            ans = max(ans,heights[index] * (nse - pse - 1));
        }
        return ans;
    }
};*/
