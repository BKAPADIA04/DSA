class Solution {
public:
    struct Node {
        int links[26];
        int idx;

        Node() {
            for (int i = 0; i < 26; i++) links[i] = -1;
            idx = -1;
        }
    };

    vector<Node> trie;

    bool better(int newIdx, int oldIdx, vector<string>& wordsContainer) {
        if (oldIdx == -1) return true;

        int lenNew = wordsContainer[newIdx].size();
        int lenOld = wordsContainer[oldIdx].size();

        if (lenNew != lenOld) return lenNew < lenOld;
        return newIdx < oldIdx;
    }

    void updateBest(int node, int idx, vector<string>& wordsContainer) {
        if (better(idx, trie[node].idx, wordsContainer)) {
            trie[node].idx = idx;
        }
    }

    void insertWord(string& word, int idx, vector<string>& wordsContainer) {
        int curr = 0;

        updateBest(curr, idx, wordsContainer);

        for (int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';

            if (trie[curr].links[ch] == -1) {
                trie[curr].links[ch] = trie.size();
                trie.push_back(Node());
            }

            curr = trie[curr].links[ch];
            updateBest(curr, idx, wordsContainer);
        }
    }

    int query(string& word) {
        int curr = 0;
        int ans = trie[curr].idx;

        for (int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';

            if (trie[curr].links[ch] == -1) {
                break;
            }

            curr = trie[curr].links[ch];
            ans = trie[curr].idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.reserve(500005);
        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insertWord(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        for (string& q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};
