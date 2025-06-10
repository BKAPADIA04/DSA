class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string,int>umap;
        int j = 0; string temp = "";
        for(int i = 0;i < n;i++) {
            j++;
            if(j % k == 0) {
                temp = word.substr(i - k + 1, k);
                // cout << temp <<  endl;
                umap[temp]++;
                j = 0;
            } 
        }

        int req = n/k;
        int ans = req;
        for(auto it : umap) {
            ans = min(ans,req - it.second);
        }
        return ans;
    }
};
