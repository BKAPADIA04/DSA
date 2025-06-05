class Solution {
public:

    vector<int>parent;vector<int>size;

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultX = findParent(u);
        int ultY = findParent(v);
        if(ultX == ultY) return;
        if(size[ultX] > size[ultY]) {
            size[ultX] += size[ultY];
            parent[ultY] = ultX;
        }
        else {
            size[ultY] += size[ultX];
            parent[ultX] = ultY;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent = vector<int>(26,0);
        for(int i = 0;i < 26;i++) parent[i] = i;
        size = vector<int>(26,1);
        unordered_set<int>freq;

        int n = s1.size();
        for(int i = 0;i < n;i++) {
            freq.insert(s1[i] - 'a');
            freq.insert(s2[i] - 'a');

            unionBySize(s1[i] - 'a',s2[i] - 'a');
        }

        string answer;
        for(int i = 0;i < baseStr.size();i++) {
            char ch = baseStr[i];
            int ult = findParent(ch - 'a');
            char mini = ch;
            for(int j = 0;j < 26;j++) {
                if(findParent(j) == ult) {
                    mini = min(mini,(char)(j + 97));
                }
            }
            answer.push_back(mini);
        }
        return answer;
    }
};
