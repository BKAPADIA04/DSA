#include <bits/stdc++.h> 

struct Node {
    Node * links[26];
    bool flag = false;
    int countEndWith = 0;
    int countPrefixWith = 0;

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch,Node * node) {
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

class Trie{

    private:
    Node * root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node * node = root;
        for(int i = 0;i < word.size();i++) {
            if (!(node->contains(word[i]))) {
                node->put(word[i], new Node());
            }
            node = node->next(word[i]);
            node->countPrefixWith += 1;
        }
        node->countEndWith += 1;
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node * node = root;
        for(int i = 0;i < word.size();i++) {
            if (!(node->contains(word[i]))) {
                return 0;
            }
            node = node->next(word[i]);
        }
        return node->countEndWith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node * node = root;
        for(int i = 0;i < word.size();i++) {
            if (!(node->contains(word[i]))) {
                return 0;
            } else {
                node = node->next(word[i]);
            }
        }
        return node->countPrefixWith;
    }

    void erase(string &word){
        // Write your code here.
        Node * node = root;
        for(int i = 0;i < word.size();i++) {
            if (!(node->contains(word[i]))) {
                return;
            }
            node = node->next(word[i]);
            node->countPrefixWith -= 1;
        }
        node->countEndWith -= 1;
    }
};
