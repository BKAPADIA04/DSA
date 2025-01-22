#include <bits/stdc++.h>
using namespace std;

void print(set<string>st) {
    for(auto it:st) cout << it << endl;
}
// Brute force approach
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n = s.size();
    set <string> st;
    for(int i = 0;i < n;i++) {
        string temp = "";
        for(int j = i;j >= 0;j--) {
            temp = s[j] + temp;
            if(st.find(temp) == st.end()) st.insert(temp);
        }
    }
    print(st);
    return st.size() + 1;
}

int main() {
    string s = "abc";
    cout << countDistinctSubstrings(s) << endl;
    return 0;
}
// Time complexity: O(n^2)
// Space complexity: O(n^3) n2 *avg size(n/2) = n^3/2
// Optimized approach

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

int countDistinctSubstrings(string &s)
{
    Node * root = new Node();
    int count = 0;
    for(int i = 0;i < s.size();i++) {
        Node * node = root;
        for(int j = i;j < s.size();j++) {
            if(!node->contains(s[j])) {
                node->put(new Node(), s[j])
                count++;
            } 
            node = node->next(s[j]);
        }
    }
    return count + 1;
}
// Time complexity: O(n^2)
// Space complexity: O(n^2) only the number of characters 