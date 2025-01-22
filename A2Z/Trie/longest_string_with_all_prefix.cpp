#include <bits/stdc++.h> 

struct Node {
    Node * links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch-'a'] != nullptr;
    }

    Node * next(char ch) {
        return links[ch - 'a'];
    }

    void put(Node * node,char ch) {
        links[ch-'a'] = node;
    }

    void setEnd(){flag = true;}

    bool isEnd() { return flag; }
};

void insert(string str,Node * root) {
    int n = str.size();
    Node * node = root;
    for(int i = 0;i < n;i++) {
        if(!(node->contains(str[i]))) {
            node->put(new Node(),str[i]);
        }
        node = node->next(str[i]);
    }
    node->setEnd();
}

bool search(string str,Node * root) {
    Node * node = root;
    int n = str.size();
    for(int i = 0;i < n;i++) {
        if(!(node->contains(str[i]))) {
            return false;
        }
        node = node->next(str[i]);
        if(node->isEnd() == false) return false;
    }
    return true;
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    Node * root = new Node();
    for(int i = 0;i < n;i++) {
        insert(a[i],root);
    }
    string answer = "";
    for(int i = 0;i < n;i++) {
        bool check = search(a[i],root);
        if(check) {
            if(a[i].size() > answer.size()) answer = a[i];
            else if(a[i].size() == answer.size()) answer = min(answer,a[i]);
        }
    }
    if(answer.size() == 0) return "None";
    return answer;

}