class Solution {
public:

    void dfs(int node, int src, int start, int end, vector<vector<pair<int,int>>>&adj,vector<int>&nums,int pathSum,unordered_map<int,int>&colors,int &maxLength, int &minNodes,vector<int>&path) {
        int prevIndex = colors.count(nums[node]) > 0 ? colors[nums[node]] : -1;
        while(start <= prevIndex) {
            pathSum -= path[start++];
        }
        if(pathSum > maxLength) {
            maxLength = pathSum;
            minNodes = end-start+1;
        }
        else if(pathSum == maxLength) {
            minNodes = min(minNodes,end-start+1);
        }

        colors[nums[node]] = end;

        for(auto it:adj[node]) {
            int nbhd = it.first;
            int wt = it.second;

            if(nbhd == src) continue;
            path.push_back(wt);
            dfs(nbhd,node,start,end+1,adj,nums,pathSum + wt,colors,maxLength,minNodes,path);
            path.pop_back();
        } 
        colors[nums[node]] = prevIndex;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        vector<int>path = {};
        unordered_map<int,int>colors;

        int maxLength = INT_MIN; int minNodes = INT_MAX; int start = 0; int end = 0; int pathSum = 0;

        dfs(0,-1,start,end,adj,nums,pathSum,colors,maxLength,minNodes,path);

        return {maxLength,minNodes};
    }
};