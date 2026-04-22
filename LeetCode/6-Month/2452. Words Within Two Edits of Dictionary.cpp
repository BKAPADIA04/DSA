struct Node {
    Node * links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node * node) {
        links[ch - 'a'] = node;
    }

    Node * next(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Solution {
public:

    Node * root = new Node();

    void insert(string word) {
        int n = word.size();
        Node * node = root;
        for(int i = 0;i < n;i++) {
            char ch = word[i];
            if(!node->contains(ch)) node->put(ch, new Node());
            node = node->next(ch);
        }
        node->setEnd();
    }

    bool dfs(string &str, int i, int cnt, Node * node) {
        if(cnt > 2) return false;
        if(!node) return false;
        if(i == (int)str.size()) return node->isEnd();

        char ch = str[i];
        int idx = ch - 'a';

        if(node->contains(str[i])) {
            if(dfs(str, i + 1, cnt, node->next(ch))) return true;
        }

        if(cnt < 2) {
            for(int j = 0;j < 26;j++) {
                if(idx == j) continue;
                if(node->contains((char)(j + 'a'))) {
                    if(dfs(str, i + 1, cnt + 1, node->next((char)(j + 'a')))) return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

        for(string dic:dictionary) {
            insert(dic);
        }                            

        vector<string> ans;
        for (string query : queries) {
            if(dfs(query, 0,0, root)) ans.push_back(query);
        }
        return ans;
    }
};
