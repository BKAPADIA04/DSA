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