#define ll long long
class Solution {
public:

    void print(vector<int>&subChilds) {
        for(auto it:subChilds) cout << it << " ";
        cout << endl;
    }

    void dfs(vector<vector<int>>&adj,int index,vector<int>&subChilds,vector<int>&visited) {
        visited[index] = 1;
        for(auto it:adj[index]) {
            if(!visited[it]) {
                dfs(adj,it,subChilds,visited);
                subChilds[index] += subChilds[it];
            }
        }
    }

    int countHighestScoreNodes(vector<int>& parent) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i = 0;i < n;i++) {
            if(parent[i] == -1) continue;
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        vector<int>subChilds(n,1);
        vector<int>visited(n,0);
        dfs(adj,0,subChilds,visited);
        ll maxi = 0; int answer = 0;
        for(int i = 0;i < n;i++) {
            ll temp = (n - subChilds[i]) * 1ll;
            if(temp == 0) temp = 1ll;
            for(auto it:adj[i]) {
                if(it == parent[i]) continue;
                temp *= subChilds[it];
            }
            if(temp > maxi) {
                maxi = temp; answer = 1;
            }
            else if(temp == maxi) {
                answer++;
            }
        }
        // print(subChilds);
        return answer;
    }
};
