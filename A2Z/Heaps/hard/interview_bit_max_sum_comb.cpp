#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>ans;
    int n = A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    priority_queue<vector<int>>pq;
    set<pair<int, int> > s;

    pq.push({A[n-1] + B[n-1],n-1,n-1});
    s.insert({n-1,n-1});
    for(int i = 0;i<C;i++) {
        vector<int>temp = pq.top();
        pq.pop();
        ans.push_back(temp[0]);
        int x = temp[1];
        int y = temp[2];

        int sum = A[x - 1] + B[y];
        pair<int, int> temp1 = make_pair(x - 1, y);
        if (s.find(temp1) == s.end()) 
        {
            pq.push({sum,temp1.first,temp1.second});
            s.insert(temp1);
        }

        sum = A[x] + B[y - 1];
        temp1 = make_pair(x, y - 1);
        if (s.find(temp1) == s.end()) 
        {
            pq.push({sum,temp1.first,temp1.second});
            s.insert(temp1);
        }
    }
    return ans;
}

int main() {
    vector<int>A = {1,4,2,3};
    vector<int>B = {2,5,1,6};
    int C = 4;
    vector<int>ans = solve(A,B,C);
    for(int i:ans) cout << i << " ";
    cout << endl;
}