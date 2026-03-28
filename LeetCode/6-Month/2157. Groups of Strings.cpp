class Solution {
public:

    int n;
    vector<int>parent;
    vector<int>size;

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unite(int x, int y) {
        int ultX = findParent(x);
        int ultY = findParent(y);
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

    vector<int> groupStrings(vector<string>& words) {
        n = words.size();
        parent = vector<int>(n, 0);
        size = vector<int>(n,1);
        
        for(int i = 0; i < n;i++) parent[i] = i;
        unordered_map<int, int> mp; 
        // mp[0]

        for(int i = 0;i < n;i++) {
            int hash = 0;
            for(char ch : words[i]) hash |= (1 << (ch - 'a'));
            for(int j = 0;j < 26;j++) {
                if(hash & (1 << j)) {
                    int delHash = hash ^ (1 << j);
                    if(mp.count(delHash) > 0) unite(i, mp[delHash]);
                    for(int k = 0;k < 26;k++) {
                        int replaceHash = delHash | (1 << k);
                        if(replaceHash != delHash && mp.count(replaceHash) > 0) unite(i, mp[replaceHash]);
                    }
                }
                else {
                    int addHash = hash | (1 << j);
                    if(mp.count(addHash) > 0) unite(i, mp[addHash]);
                }
            }
            mp[hash] = i;
        }

        int numGrps = 0; int maxiSize = 1;
        // for(auto it : parent) cout << it << " ";
        for(int i = 0;i < n;i++) {
            if(findParent(i) == i) {
                numGrps++;
                maxiSize = max(maxiSize, size[i]);
            }
        }

        return {numGrps, maxiSize};
    }
};
