class Solution {
public:
    static bool comp(string &s1,string &s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1); int maxi = 1;

        for(int i = 0;i < n;i++) {
            string str1 = words[i];
            for(int j = 0;j < i;j++) {
                string str2 = words[j];
                int k = 0; int l = 0; int count = 0;
                while(k < str1.size() && l < str2.size()) {
                    if(str1[k] == str2[l]) {
                        l++;
                    }
                    else {
                        count++;
                    }
                    k++;
                }
                count += str1.size() - k;
                if(count <= 1 && l == str2.size() && (str1.size() == str2.size() + 1)) {
                    cout << str2 << " " << str1 << endl;
                    dp[i] = max(dp[i],1 + dp[j]);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};