class Solution {
public:

    bool isValid(int n,int m,int x,int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return false;
        return true;
    }

    void bfs(vector<vector<int>>&grid, vector<pair<int,int>>&v,vector<int>&answer, int n, int m,int sz) {
        vector<vector<int>>visited(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
        int index = 0;
        // if(grid[0][0] >= v[index].first) return;
        minHeap.push({grid[0][0],0,0}); visited[0][0] = 1;
        int ans = 0;

        vector<int>x_coord = {-1,0,1,0}; vector<int>y_coord = {0,1,0,-1};
        while(index < sz) {
            while(!minHeap.empty() && minHeap.top()[0] < v[index].first) {
                vector<int>temp = minHeap.top();
                int lead = temp[0]; int x = temp[1]; int y = temp[2];
                minHeap.pop();
                for(int i = 0;i < 4;i++) {
                    int x_new = x + x_coord[i]; int y_new = y + y_coord[i];
                    if(isValid(n,m,x_new,y_new) && !visited[x_new][y_new]) {
                        visited[x_new][y_new] = 1;
                        minHeap.push({grid[x_new][y_new],x_new,y_new});
                    }
                }
                ans++;
            }
            answer[v[index].second] = ans;
            index++;
        }
        if(index < sz) {
            for(int i = index;i < sz;i++) answer[v[index].second] = ans;
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(); int m = grid[0].size(); int sz = queries.size();
        vector<int>answer(sz,0);
        vector<pair<int,int>>v;
        for(int i = 0;i < sz;i++) {
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        bfs(grid,v,answer,n,m,sz);
        // for(auto it:answer) cout << it << " ";
        return answer;
    }
};
