class Solution {
public:

    vector<int>dp;

    void generate(vector<int>&nodes, vector<vector<int>>&result, vector<int>currentCombination, int i, int k) {
        if(k == 0) {
            result.push_back(currentCombination);
            return;
        }

        for(int j = i;j < (int)nodes.size();j++) {
            currentCombination.push_back(nodes[j]);
            generate(nodes, result, currentCombination, j + 1, k - 1);
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> generateCombinations(vector<int>&nodes, int k) {
        vector<vector<int>>result;
        vector<int>currCombination;
        generate(nodes, result, currCombination, 0, k);
        return result;
    }

    int check(int mask , vector<int>& inDegree , vector<vector<int>>&adj , int k) {
        if(mask == 0) return 0;

        if(dp[mask] != -1) return dp[mask];

        int ans = INT_MAX;
        vector<int>nodes;
        for(int i = 0;i < adj.size();i++) {
            if((mask & (1 << i)) && inDegree[i] == 0) {
                nodes.push_back(i);
            }
        }

        int m = nodes.size();
        vector<vector<int>>result = generateCombinations(nodes, min(k,m));

        for(auto it : result) {
            int newMask = mask;
            vector<int>newIndegree = inDegree;

            for(auto i:it) {
                newMask ^= (1 << i);
                for(auto child:adj[i]) {
                    newIndegree[child]--;
                }
            }

            ans = min(ans, 1 + check(newMask,newIndegree,adj,k));
        }
        return dp[mask] = ans;
    }


    int minNumberOfSemesters(int n, vector<vector<int>>& nums, int k) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(int i = 0;i < (int)nums.size();i++) {
            adj[nums[i][0] - 1].push_back(nums[i][1] - 1);
            indegree[nums[i][1] - 1]++;
        }

        int mask = 0;
        for(int i = 0;i < n;i++) {
            mask ^= (1 << i);
        }

        dp = vector<int>(mask + 1,-1);

        return check(mask,indegree,adj,k);
    }
};
