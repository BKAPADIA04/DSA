class Solution {
public:
    
    int n;
    vector<int>parent;

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unite(int x, int y) {
        int ultX = findParent(x);
        int ultY = findParent(y);
        if(ultX == ultY) return;
        parent[ultX] = ultY;
    }

    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        parent = vector<int>(n, 0);
        unordered_map<string, int>st;
        for(int i = 0; i < n;i++) { parent[i] = i; st[strs[i]] = i; }

        string temp = "";
        int len = strs[0].size();
        for(int i = 0;i < n;i++) {
            temp = strs[i];
            for(int j = 0;j < len;j++) {
                for(int k = j;k < len;k++) {
                    swap(temp[j], temp[k]);
                    if(st.find(temp) != st.end()) unite(i, st[temp]);
                    swap(temp[j], temp[k]);
                }
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++) {
            if(findParent(i) == i) ans++;
        }

        return ans;
    }
};
