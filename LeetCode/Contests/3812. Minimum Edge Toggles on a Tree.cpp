class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int> s;
    vector<int> t;
    vector<int> answer;

    void check(int node, int parent, int edge) {
        for(auto it : adj[node]) {
            if(it.first == parent) continue;
            check(it.first,node,it.second);
        }

        if(s[node] != t[node] && edge != -1) {
            answer.push_back(edge);
            s[node] ^= 1;
            s[parent] ^= 1;
        } 
    }


    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {

        adj = vector<vector<pair<int,int>>>(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],i});
            adj[edges[i][1]].push_back({edges[i][0],i});
        }

        int count = 0;
        for(int i = 0;i < start.size();i++) {
            if(start[i] != target[i]) count++;
        }
        if(count & 1) return {-1};

        //strings are bad for doing xor ;)
        for(auto c : start){
            if(c == '1') s.push_back(1);
            else s.push_back(0);
        }
        for(auto c : target){
            if(c == '1') t.push_back(1);
            else t.push_back(0);
        }

        check(0,0,-1);
        if(s[0] != t[0]) return {-1};
        sort(answer.begin(),answer.end());
        return answer;
    }
};
