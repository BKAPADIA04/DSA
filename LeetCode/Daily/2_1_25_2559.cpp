class Solution {
public:
    void print(vector<int>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n+1,0);
        for(int i = 1;i <= n;i++) {
            string str = words[i-1];
            char ch1 = str[0]; char ch2 = str[str.size()-1];
            int check = (ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u') && (ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u');
            prefix[i] = prefix[i-1] + check;
        }

        print(prefix);

        vector<int>ans(queries.size(),0);
        for(int i = 0;i < queries.size();i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = prefix[r+1] - prefix[l];
        }
        return ans;
    }
};
