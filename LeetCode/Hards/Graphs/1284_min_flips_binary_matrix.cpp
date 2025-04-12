class Solution {
public:

    int flip(int state, int i, int j, int n, int m) {
        vector<int>x_coord = {0,-1,0,1,0};
        vector<int>y_coord = {0,0,1,0,-1};

        for(int k = 0;k < 5;k++) {
            int x = i + x_coord[k];
            int y = j + y_coord[k];
            if(x < 0 || y < 0 || x >= n || y >= m) {
                continue;
            }
            int newcoord = x + n * y;
            state ^= (1 << newcoord);
        }

        return state;
    }

    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int target = 0;
        int state = 0;

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(mat[i][j]) state |= (1 << (i + n * j));
            }
        }

        queue<pair<int,int>>q;
        unordered_set<int>visited;

        q.push({state,0});
        visited.insert(state);

        while(!q.empty()) {
            int currState = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(currState == target) return steps;

            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    int nextState = flip(currState, i, j, n, m);
                    if(visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push({nextState, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};
