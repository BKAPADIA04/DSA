class Solution {
public:

    int find(vector<int>&parent,int X) {
        if(parent[X] == X) return X;
        return parent[X] = find(parent,parent[X]);
    }

    void unionByRank(vector<int>&parent,vector<int>&rank,int X,int Y) {
        int ult_X = find(parent,X);
        int ult_Y = find(parent,Y);
        if(ult_X == ult_Y) return;
        if(rank[ult_X] > rank[ult_Y]) {
            parent[ult_Y] = ult_X;
        }
        else if(rank[ult_Y] > rank[ult_X]) {
            parent[ult_X] = ult_Y;
        }
        else {
            parent[ult_Y] = ult_X;
            rank[ult_X]++;
        }
    }

    int MST(int n,vector<vector<int>>&edges,int missingEdge,int includingEdge) {
        int answer = 0;
        vector<int>parent(n,0); vector<int>rank(n,0);
        for(int i = 0;i < n;i++) {
            parent[i] = i;
        }
        if(includingEdge != -1) {
            answer += edges[includingEdge][2];
            int u = edges[includingEdge][0]; int v = edges[includingEdge][1];
            unionByRank(parent,rank,u,v);
        }
        for(int i = 0;i < edges.size();i++) {
            if(i == missingEdge) continue;
            int u = edges[i][0]; int v = edges[i][1]; int wt = edges[i][2];

            if(find(parent,u) == find(parent,v)) continue;

            answer += wt;
            unionByRank(parent,rank,u,v);
        }

        for(int i = 0;i < edges.size();i++) {
            if(find(parent,edges[i][0]) != find(parent,edges[i][1])) return 1e9;
        }
        return answer;
    }

    static bool comparator(vector<int>&e1,vector<int>&e2) {
        return e1[2] < e2[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0;i < edges.size();i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),comparator);
        int originalMST = MST(n,edges,-1,-1);
        
        vector<int>critical,pseudo;
        
        for(int i = 0;i < edges.size();i++) {
            if(MST(n,edges,i,-1) > originalMST) {
                critical.push_back(edges[i][3]);
            }
            else if(MST(n,edges,-1,i) == originalMST) {
                pseudo.push_back(edges[i][3]);
            }
        }
        vector<vector<int>>answer;
        answer.push_back(critical);
        answer.push_back(pseudo);
        return answer;
    }
};
