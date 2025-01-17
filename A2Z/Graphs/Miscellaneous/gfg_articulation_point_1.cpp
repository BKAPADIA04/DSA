//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfs(vector<int>adj[],vector<int>&visited,vector<int>&arti,vector<int>&in,vector<int>&low,int i,int par,int &timer) {
        visited[i] = 1;
        in[i] = low[i] = timer;
        timer += 1;
        int child = 0;
        for(auto it:adj[i]) {
            if(it == par) continue;
            if(!visited[it]) {
                dfs(adj,visited,arti,in,low,it,i,timer);
                low[i] = min(low[i],low[it]);
                child++;
                if(low[it] >= in[i] && par != -1) arti[i] = 1;
            }
            else {
                low[i] = min(low[i],in[it]);
            }
        }
        if(child > 1 && par == -1) arti[0] = 1;
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>visited(V),in(V),low(V);
        vector<int>arti(V);
        int timer = 1;
        dfs(adj,visited,arti,in,low,0,-1,timer);
        
        vector<int>ans;
        for(int i = 0;i < V;i++) {
            if(arti[i] == 1) ans.push_back(i);
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends