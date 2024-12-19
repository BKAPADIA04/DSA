class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,vector<int>&visited,int index) {
        vector<int>v = isConnected[index];
        for(int i = 0;i < v.size();i++) {
            if(v[i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dfs(isConnected,visited,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(visited[i] == 0) {
                count++;
                visited[i] = 1;
                dfs(isConnected,visited,i);
            }
        }
        return count;
    }
};