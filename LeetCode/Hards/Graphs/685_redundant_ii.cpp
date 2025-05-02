// class Solution {
// public:

//     int findParent(vector<int>&parent, int node) {
//         if(parent[node] == node) return node;
//         return parent[node] = findParent(parent,parent[node]);
//     }
    
//     bool unionBySize(vector<int>&parent, vector<int>&size, int u, int v) {
//         int ultU = findParent(parent,u);
//         int ultV = findParent(parent,v);
//         if(ultU == ultV) return false;
//         if(size[ultU] < size[ultV]) {
//             parent[ultU] = ultV;
//             size[ultV] += size[ultU];
//         }
//         else {
//             parent[ultV] = ultU;
//             size[ultU] += size[ultV];
//         }
//         return true;
//     }

//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<int>parent(n + 1,0); vector<int>size(n + 1,1); size[0] = 0;
//         for(int i = 1;i <= n;i++) parent[i] = i;

//         int conflictIndex = -1; int cycleIndex = -1;
//         for(int i = 0;i < n;i++) {
//             int u = edges[i][0]; int v = edges[i][1];
//             if(findParent(parent, v) != v) conflictIndex = i;
//             else {
//                 parent[v] = u;
//                 if(!unionBySize(parent,size,u,v)) {
//                     cycleIndex = i;
//                 }
//             }
//         }

//         if(conflictIndex == -1) return edges[cycleIndex];
//         int v = edges[conflictIndex][1];
//         if(cycleIndex != -1) {
//             return {findParent(parent,v),v};
//         }
//         return edges[conflictIndex]; 
//     }
// };

#include <vector>
#include <numeric>
using namespace std;

// Class UnionFind represents a data structure for disjoint-set operations.
class UnionFind {
public:
    // p stores the parent of each element, n represents the number of elements.
    vector<int> parent;
    int num_sets;

    // Constructor initializes a disjoint-set for n elements.
    UnionFind(int n)
        : num_sets(n)
        , parent(n) {
        // iota fills the parent vector with increasing values starting from 0,
        // so each element is initially in its own set.
        iota(parent.begin(), parent.end(), 0);
    }

    // Method to unite two sets. Returns true if a union was performed, else false.
    bool unite(int a, int b) {
        int parent_a = find(a), parent_b = find(b);
        // If both elements have the same parent, they are already connected, so no union is performed.
        if (parent_a == parent_b) return false;
        // Assign one element's parent to the other, effectively merging the sets.
        parent[parent_a] = parent_b;
        // Decrement the count of disjoint sets.
        --num_sets;
        return true;
    }

    // Find method with path compression. Finds the representative of the set containing x.
    int find(int x) {
        if (parent[x] != x) {
            // Recursively find the parent and perform path compression.
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

// Solution class contains methods to analyze the graph and find the redundant edge.
class Solution {
public:
    // Method to find the redundant directed connection in a graph represented by the edges list.
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int num_edges = edges.size();
        // p keeps track of direct parents for each node.
        vector<int> direct_parents(num_edges + 1);
        for (int i = 0; i <= num_edges; ++i) direct_parents[i] = i;
        UnionFind uf(num_edges + 1);
        int conflict_edge_idx = -1, cycle_edge_idx = -1;

        // Iterate over the edges to find any cycle or conflict.
        for (int i = 0; i < num_edges; ++i) {
            int u = edges[i][0], v = edges[i][1];
            // If v already has a parent, we have found a conflict.
            if (direct_parents[v] != v) {
                conflict_edge_idx = i;
            } else {
                // Assign parent for v.
                direct_parents[v] = u;
                // If the union operation indicates a cycle, record the current edge index.
                if (!uf.unite(u, v)) {
                    cycle_edge_idx = i;
                }
            }
        }

        // If there's no conflict, the redundant connection must be part of a cycle.
        if (conflict_edge_idx == -1) {
            return edges[cycle_edge_idx];
        }

        // If a cycle exists when a conflict is found, we return the previous edge that caused the cycle with the conflicting node.
        int v = edges[conflict_edge_idx][1];
        if (cycle_edge_idx != -1) {
            return {direct_parents[v], v};
        }
        // If there's only a conflict without a cycle, we return the conflicting edge.
        return edges[conflict_edge_idx];
    }
};
