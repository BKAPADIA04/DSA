#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // Base case: if k is 0, all nodes can only reach themselves.
        if (k == 0) {
            return vector<int>(edges1.size() + 1, 1);
        }

        // Initialize adjacency lists for both trees
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adjacencyList1(n1), adjacencyList2(n2);

        // Build adjacency list for the first tree
        for (auto& edge : edges1) {
            adjacencyList1[edge[0]].push_back(edge[1]);
            adjacencyList1[edge[1]].push_back(edge[0]);
        }

        // Build adjacency list for the second tree
        for (auto& edge : edges2) {
            adjacencyList2[edge[0]].push_back(edge[1]);
            adjacencyList2[edge[1]].push_back(edge[0]);
        }

        // Function to calculate reachable nodes within a given distance for a tree
        auto calculateReachableNodes_BFS = [](vector<vector<int>>& adjacencyList, int maxDistance) {
            int n = adjacencyList.size();
            vector<int> reachCounts(n, 0);
            
            for (int startNode = 0; startNode < n; ++startNode) {
                vector<bool> visited(n, false);
                queue<int> q;
                q.push(startNode);
                visited[startNode] = true;
                int level = 0;

                while (!q.empty() && level < maxDistance) {
                    int lenQ = q.size();
                    ++level;

                    for (int i = 0; i < lenQ; ++i) {
                        int currentNode = q.front();
                        q.pop();
                        
                        for (int neighbor : adjacencyList[currentNode]) {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push(neighbor);
                            }
                        }
                    }
                }
                reachCounts[startNode] = count(visited.begin(), visited.end(), true);
            }
            return reachCounts;
        };

        // Calculate reachable nodes for the first tree within distance k
        vector<int> reachableCount1 = calculateReachableNodes_BFS(adjacencyList1, k);

        // Calculate reachable nodes for the second tree within distance k-1
        vector<int> reachableCount2 = calculateReachableNodes_BFS(adjacencyList2, k - 1);

        // Find the maximum reachable nodes in the second tree
        int maxReachableInTree2 = *max_element(reachableCount2.begin(), reachableCount2.end());

        // Add the maximum from the second tree to each node's reachable count in the first tree
        for (int i = 0; i < reachableCount1.size(); ++i) {
            reachableCount1[i] += maxReachableInTree2;
        }

        return reachableCount1;
    }
};
