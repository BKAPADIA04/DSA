class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        int n = s.size(); 
        int m = words.size();
        map<char,vector<int>>umap;
        for(int i = 0;i < n;i++) {
            umap[s[i]].push_back(i);
        }

        for(int i = 0;i < m;i++) {
            int curr = -1; int j;
            string word = words[i];
            int jSize = word.size();
            for(j = 0;j < jSize;j++) {
                auto index = upper_bound(umap[word[j]].begin(),umap[word[j]].end(),curr);
                if(index == umap[word[j]].end()) {
                    break;
                }
                curr = *index;
                if(j == jSize - 1) ans++;
            }    
        }
        return ans;
    }
};
