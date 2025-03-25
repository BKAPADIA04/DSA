class Solution {
public:

    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //     set<string>s(wordList.begin(),wordList.end());
    //     queue<vector<string>>q;
    //     q.push({beginWord});
    //     vector<string>usedOnLevel;
    //     usedOnLevel.push_back(beginWord);
    //     int level = 0;
    //     vector<vector<string>>ans;
    //     while(!q.empty()) {
    //         vector<string>vec = q.front(); q.pop();
    //         string word = vec.back();

    //         if(vec.size() > level) {
    //             level++;
    //             for(auto it:usedOnLevel) {
    //                 s.erase(it);
    //             }
    //             usedOnLevel.clear();
    //         }

    //         if(endWord == word) {
    //             if(ans.size() == 0) ans.push_back(vec);
    //             else if(ans[0].size() == vec.size()) ans.push_back(vec);
    //         }

    //         for(int i = 0;i < word.size();i++) {
    //             char original = word[i];
    //             for(char ch = 'a';ch <= 'z';ch++) {
    //                 word[i] = ch;
    //                 if(s.count(word) > 0) {
    //                     vec.push_back(word);
    //                     usedOnLevel.push_back(word);
    //                     q.push(vec);
    //                     vec.pop_back();
    //                 }
    //             }
    //             word[i] = original;
    //         }
    //     }
    //     return ans;
    // }

    unordered_map<string,int>umap;
    vector<vector<string>>ans;
    string b;

    void dfs(string word, vector<string>&seq) {
        if(word == b) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int check = umap[word];
        for(int i = 0;i < b.size();i++) {
            char original = word[i];
            for(char ch = 'a';ch <= 'z';ch++) {
                word[i] = ch;
                if(umap.find(word) != umap.end() && umap[word] + 1 == check) {
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        umap[beginWord] = 1;
        b = beginWord;
        s.erase(beginWord);
        while(!q.empty()) {
            string word = q.front(); q.pop();
            if(word == endWord) break;
            int steps = umap[word];
            for(int i = 0;i < beginWord.size();i++) {
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++) {
                    word[i] = ch;
                    if(s.count(word) > 0) {
                        q.push(word);
                        s.erase(word);
                        umap[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(umap.find(endWord) != umap.end()) {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};
