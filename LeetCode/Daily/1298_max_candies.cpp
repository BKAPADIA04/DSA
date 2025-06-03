class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int>q;
        vector<int>visited(n,0);
        vector<int>canOpen(n,0);
        vector<int>hasBox(n,0);
        int answer = 0;

        for(int i = 0;i < n;i++) {
            canOpen[i] = (status[i] == 1);
        }

        for(int i : initialBoxes) {
            hasBox[i] = 1;
            if(canOpen[i]) {
                visited[i] = 1;
                q.push(i);
                answer += candies[i];
            }
        }

        while(!q.empty()) {
            int box = q.front();
            q.pop();
            for(auto it : keys[box]) {
                canOpen[it] = 1;
                if(!visited[it] && hasBox[it]) {
                    visited[it] = 1;
                    q.push(it);
                    answer += candies[it];
                }
            }

            for(auto it : containedBoxes[box]) {
                hasBox[it] = 1;
                if(!visited[it] && canOpen[it]) {
                    visited[it] = 1;
                    q.push(it);
                    answer += candies[it];
                }
            }
        }
        return answer;
    }
};
