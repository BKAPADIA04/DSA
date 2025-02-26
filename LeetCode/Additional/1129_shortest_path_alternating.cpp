class Solution {
public:

    void print(vector<int>v) { for(auto it:v) cout << it << " "; }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>adj1(n),adj2(n);
        for(int i = 0;i < redEdges.size();i++) {
            adj1[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i = 0;i < blueEdges.size();i++) {
            adj2[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        vector<vector<int>>visited(2,vector<int>(n,0));
        vector<int>answer(n,-1);
        queue<pair<int,int>>q;
        q.push({0,0}); // node and color
        q.push({0,1}); // color = 0 -> red and color = 0 -> white

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0;i < size;i++) {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();

                if(answer[node] == -1) answer[node] = level;
                visited[color][node] = 1;

                color ^= 1;

                if(color == 0) {
                    for(auto it:adj1[node]) {
                        if(!visited[color][it]) {
                            q.push({it,color});
                        }
                    }
                }
                else {
                    for(auto it:adj2[node]) {
                        if(!visited[color][it]) {
                            q.push({it,color});
                        }
                    }
                }
            }
            level++;
        }
        return answer;
    }   
};
