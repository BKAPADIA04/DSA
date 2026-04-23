class Solution {
public:
    vector<vector<int>>graph;
    int n;

    int dp[55][55][3];

    int check(int catPos, int mousePos, int turn, map<vector<int>, bool>&mp) {
        if(mousePos == 0) return 1;
        if(catPos == mousePos) return 2;
        
        if(dp[catPos][mousePos][turn] != -1) return dp[catPos][mousePos][turn];

        vector<int>state = {catPos, mousePos, turn};
        if(mp[state]) return 0;

        mp[state] = true;

        bool draw = false;

        if(turn == 1) {
            for(auto it : graph[mousePos]) {
                int tmp = check(catPos, it, 2, mp);
                if(tmp == 0) draw = true;
                else if(tmp == 1) return dp[catPos][mousePos][turn] = 1; // turn
            }
        }
        else {
            for(auto it : graph[catPos]) {
                if(it == 0) continue
                int tmp = check(it, mousePos, 1, mp);
                if(tmp == 0) draw = true;
                else if(tmp == 2) return dp[catPos][mousePos][turn] = 2; // turn
            }
        }

        mp[state] = false;

        if(draw) return dp[catPos][mousePos][turn] = 0;

        if(turn == 1) {
            return dp[catPos][mousePos][turn] = 2;
        }

        return dp[catPos][mousePos][turn] = 1;
    }

    int catMouseGame(vector<vector<int>>& graph) {
        this->graph = graph;
        n = graph.size();
        memset(dp, -1, sizeof(dp));
        map<vector<int>,bool>mp;
        return check(2,1,1,mp);
    }
};
