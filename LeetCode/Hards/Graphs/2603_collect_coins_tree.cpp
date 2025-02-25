// class Solution {
// public:

//     int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
//         int n = coins.size();
//         vector<unordered_set<int>>adj(n);
//         for(int i = 0;i < edges.size();i++) {
//             int u = edges[i][0]; int v = edges[i][1];
//             adj[u].insert(v);
//             adj[v].insert(u);
//         }

//         queue<int>q;
//         for(int i = 0;i < n;i++) {
//             if(adj[i].size() == 1 && coins[i] == 0) {
//                 q.push(i);
//             }
//         }

//         while(!q.empty()) {
//             int node = q.front();
//             q.pop();
//             for(auto it:adj[node]) {
//                 adj[it].erase(node);
//                 if(adj[it].size() == 1 && coins[it] == 0) q.push(node); 
//             }
//             adj[node].clear();
//         }

//         for(int k = 0; k < 2;k++) {
//             vector<int>leaves;
//             for(int i = 0;i < n;i++) {
//                 if(adj[i].size() == 1) leaves.push_back(i);
//             }

//             for(auto it:leaves) {
//                 for(auto it1:adj[it]) {
//                     adj[it1].erase(it);
//                 }
//                 adj[it].clear();
//             }
//         }   

//         int count = 0;
//         for(auto it:edges) {
//             int u = it[0];
//             int v = it[1];

//             if(adj[u].size() && adj[v].size()) count += 2;
//         }        
//         return count;
//     }
// };

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int numCoins = coins.size();

        // Create an adjacency set for each node to represent the graph
        unordered_set<int> graph[numCoins];
        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            graph[nodeA].insert(nodeB);
            graph[nodeB].insert(nodeA);
        }

        // Initialize a queue to perform a BFS-like operation
        queue<int> bfsQueue;

        // Add leaf nodes with 0 coins to the queue
        for (int i = 0; i < numCoins; ++i) {
            if (coins[i] == 0 && graph[i].size() == 1) {
                bfsQueue.push(i);
            }
        }

        // Process nodes with 0 coins and remove them from graph
        while (!bfsQueue.empty()) {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();

            for (int neighbor : graph[currentNode]) {
                graph[neighbor].erase(currentNode); // Remove the edge
                if (coins[neighbor] == 0 && graph[neighbor].size() == 1) {
                    bfsQueue.push(neighbor); // Add the leaf nodes with 0 coins
                }
            }
            graph[currentNode].clear();
        }

        // Remove leaf nodes from the graph twice
        for (int iteration = 0; iteration < 2; ++iteration) {
            vector<int> leafNodes;
            for (int i = 0; i < numCoins; ++i) {
                if (graph[i].size() == 1) {
                    leafNodes.push_back(i);
                }
            }
            // Detach leaf nodes from their neighbors
            for (int leafNode : leafNodes) {
                for (int neighbor : graph[leafNode]) {
                    graph[neighbor].erase(leafNode);
                }
                graph[leafNode].clear();
            }
        }

        // Calculate the result from the remaining edges in the graph
        int result = 0;
        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            if (graph[nodeA].size() && graph[nodeB].size()) {
                result += 2; // Each remaining edge contributes 2 to the answer
            }
        }

        return result;
    }
};
