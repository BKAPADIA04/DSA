#include <bits/stdc++.h>
using namespace std;


vector<int>answer(vector<int>prices) {
    vector<int>ans;
    int n = prices.size();
    stack<pair<int,int>>st;
    for(int i = 0;i < n;i++) {
        int answer = 1;
        while(!st.empty() && st.top().first <= prices[i]) {
            answer += st.top().second;
            st.pop();
        }
        st.push({prices[i],answer});
        ans.push_back(answer);
    }
    return ans;
}

int main() {
    vector<int>prices = {7,2,1,2,2,9};
    vector<int>ans = answer(prices);
    for(int i:ans) cout << i << " ";
    cout << endl;
}