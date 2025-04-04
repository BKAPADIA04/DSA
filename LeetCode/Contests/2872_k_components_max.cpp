#define ll long long
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(edges.size() == 0) return 1;
        vector<ll>indegree(n,0);
        unordered_map<int,set<int>>mp;
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1];
            indegree[u]++; indegree[v]++;
            mp[u].insert(v); mp[v].insert(u);
        }

        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum = (totalSum % k + values[i] % k) % k; 
        }
        queue<ll>q;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }

        int answer = 0;
        while(q.size() != 1) {
            int node = q.front(); q.pop();
            bool flag = false;
            
            bool flag1 = (values[node] % k) == 0;
            bool flag2 = ((totalSum % k - values[node] % k) % k) == 0;
            if(flag1 && flag2) {
                answer++; 
                totalSum = totalSum % k - values[node] % k;
                flag = true;
            }

            for(auto it : mp[node]) {
                int parent = it;
                mp[parent].erase(node);
                indegree[parent]--;
                if(indegree[parent] == 1) {
                    q.push(parent);
                }
                if(!flag) {
                    values[parent] = (values[parent] % k + values[node] % k) % k;
                }
            }
        }

        return answer + 1;
    }   
};

/* DFS
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};*/
