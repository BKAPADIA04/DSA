class Solution {
public:

    int findRoot(int n, vector<int>&leftChild, vector<int>&rightChild) {
        unordered_set<int>s;
        for(auto it : leftChild) s.insert(it);
        for(auto it : rightChild) s.insert(it);

        for(int i = 0;i < n;i++) {
            if(s.find(i) == s.end()) return i;
        }
        return -1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if(root == -1) return false;

        queue<int>q;
        vector<int>visited(n,0);
        q.push(root);
        visited[root] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            vector<int>children = {leftChild[node], rightChild[node]};

            for(auto it : children) {
                if(it == -1) continue;
                if(visited[it]) return false;
                visited[it] = 1;
                q.push(it);
            }
        }

        return count(visited.begin(), visited.end(),1) == n;
    }
};
