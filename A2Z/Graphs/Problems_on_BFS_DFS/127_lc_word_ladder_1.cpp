class Solution {
public:

    bool check(string str1,string str2) {
        if(str1.size() != str2.size()) return false;
        int i = 0; int j = 0; int count = 0;
        while(i < str1.size() && j < str2.size()) {
            if(str1[i] != str2[j]) count++;
            i++; j++;
        }
        return count == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,bool>m;
        for(int i = 0;i < wordList.size();i++) {
            m[wordList[i]] = true;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        m[beginWord] = false;
        while(!q.empty()) {
            int count = q.front().second;
            string top = q.front().first;
            // m[top] = false;
            q.pop();
            if(top == endWord) return count;
            for(int i = 0;i < wordList.size();i++) {
                if(check(top,wordList[i]) && m[wordList[i]]) {
                    m[wordList[i]] = false;
                    q.push({wordList[i],count+1});
                }
            }
        }
        return 0;
    }
};

// another approach

class Solution {
public:
int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps= q.front().second;
            q.pop();
            if(word==targetWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char ori = word[i];
                for(char ch ='a' ; ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
    
};


        
    