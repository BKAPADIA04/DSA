class Solution {
public:

    vector<int>count(string str) {
        vector<int>c(26);
        for(auto it:str) c[it-'a']++;
        return c;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>b(26);

        for(auto str:words2) {
            vector<int>bCount = count(str);
            for(int i = 0;i < 26;i++) {
                b[i] = max(b[i],bCount[i]);
            }
        }

        for(int i = 0;i < words1.size();i++) {
                vector<int>aCount = count(words1[i]);
                bool check = true;
                for(int i = 0;i < 26;i++) {
                    if(b[i] > aCount[i]) {
                        check = false; break;
                    }
                }
            if(check) ans.push_back(words1[i]);
        }
        return ans;
    }
};
