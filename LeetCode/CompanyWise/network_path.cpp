#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>from, to,freq;
vector<vector<int>>adj;
int answer = 0;
int check(int node, int parent) {
    int maxi1 = 0; int maxi2 = 0;
    for(auto it : adj[node]) {
        if(it == parent) continue;
        int temp = check(it,node);
        if(abs(freq[node] - freq[it]) <= 1) {
            temp += 1; 
        } 
        else temp = 0;

        if(temp > maxi1) {
            maxi2 = maxi1;
            maxi1 = temp;
        }
        else if(temp > maxi2) {
            maxi2 = temp;
        }
    }

    answer = max(answer,maxi1 + maxi2);

    return max(maxi1,maxi2);
}

int main() {
    n = 4;
    from = {1,2,3};
    to = {2,3,4};
    freq = {1,3,2,1};
    adj = vector<vector<int>>(n);
    for(int i = 0;i < from.size();i++) {
        adj[from[i] - 1].push_back(to[i] - 1);
        adj[to[i] - 1].push_back(from[i] - 1);
    }
    check(0,-1);
    cout << answer << endl;

}
