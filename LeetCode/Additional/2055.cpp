class Solution {
public:
    void print(vector<int>v) { for(auto it:v) cout << it << " "; cout << endl; }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int>answer(m,0);

        map<int,int>mp; int i = 0;
        for(;i < n;i++) {
            if(s[i] != '*') break;
        }
        int count = 0; mp[i] = 0; i++;
        for(;i < n;i++) {
            if(s[i] == '*') {
                count++;
            }
            else {
                mp[i] = count;
            }
        }
        vector<int>indexes; vector<int>pre;
        for(auto it:mp) {
            indexes.push_back(it.first); pre.push_back(it.second);
        }
      
        for(int k = 0; k < m;k++) {
            int start = queries[k][0]; 
            int end = queries[k][1];

            int start_index = lower_bound(indexes.begin(),indexes.end(),start) - indexes.begin();
            int end_index = upper_bound(indexes.begin(),indexes.end(),end) - indexes.begin() - 1;
            
            if(start_index >= end_index) answer[k] = 0;
            else answer[k] = pre[end_index] - pre[start_index];
            // cout << start_index << " " << end_index << endl;
        }
        return answer;
    }
};
