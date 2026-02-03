struct Node {
    Node * links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(Node * node, char ch) {
        links[ch - 'a'] = node;
    }

    Node *next(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    public:
    Node * root;
    
    public:

    Trie(){
        root = new Node();
    }

    void insertIntoTrie(string str) {
        Node * node = root;
        reverse(str.begin(), str.end());
        for(int i = 0;i < str.size();i++) {
            if(!node->contains(str[i])) {
                node->put(new Node(), str[i]);
            }
            node = node->next(str[i]);
        }
        node->setEnd();
    }
};

class StreamChecker {
public:
    Trie *trie;
    int longestWord = 0;
    vector<char>queries;

    StreamChecker(vector<string>& words) {
        trie = new Trie();
        for(string str:words) {
            trie->insertIntoTrie(str);
            if(str.size() > longestWord) {
                longestWord = str.size();
            }
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        if(queries.size() > longestWord) queries.pop_back();

        Node *curr = trie->root;
        for(char ch : queries) {
            if(curr->isEnd()) return true;
            if(!curr->contains(ch)) return false;
            curr = curr->next(ch);
        }

        return curr->isEnd();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
