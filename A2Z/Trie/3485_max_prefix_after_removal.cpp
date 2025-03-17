#define ll long long
struct Node {
    Node *links[26];
    bool flag = false;
    int startsWith = 0;
    int length = 0;

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
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

class Solution {
public:

    Node * root;
    map<ll,ll>mp;
    set<ll,greater<ll>>s;

    Solution() {
        root = new Node();
    }

    void insert(string &word,int k) {
        int n = word.size();
        Node * node = root;
        for(int i = 0;i < n;i++) {
            if(!node->contains(word[i])) {
                node->put(word[i],new Node());
            }
            node = node->next(word[i]);
            node->startsWith += 1;
            node->length = i + 1;
            if(node->startsWith >= k) {
                mp[node->length]++;
                if(mp[node->length] == 1) s.insert(node->length);
            }
        }
        node->setEnd();
    }

    void erase(string &word,int k) {
        int n = word.size();
        Node * node = root;
        for(int i = 0;i < n;i++) {
            if(!node->contains(word[i])) {
                return;
            }
            node = node->next(word[i]);
            node->startsWith -= 1;

            if(node->startsWith == (k-1)) {
                mp[node->length]--;
                if(mp[node->length] == 0) s.erase(node->length);
            }
        }
        node->setEnd();
    }

    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int>answer(n,0);
        if(n <= k) return answer;   

        Node * node = root;

        for(int i = 0;i < words.size();i++) {
            insert(words[i],k);
        }

        for(int i = 0;i < words.size();i++) {
            erase(words[i],k);
            ll maxi = 0;
            if(s.size() == 0) answer[i] = 0;
            else {
                maxi = *s.begin();
                answer[i] = (int)maxi;
            }
            
            insert(words[i],k);
        }

        return answer;
    }
};
