class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                mp[mat[i][j]] = {i,j};
            }
        }

        vector<int>rows(m,n),cols(n,m);
        // for(int i = 0;i < m;i++) {
        //     rows[i] = n;
        // }
        // for(int i = 0;i < n;i++) {
        //     cols[i] = m;
        // }

        for(int i = 0;i < m*n;i++) {
            int x = mp[arr[i]].first;
            int y = mp[arr[i]].second;
            rows[x]--;
            cols[y]--;
            if(rows[x] == 0 || cols[y] == 0) return i;
        }
        return -1;
    }
};
