class Solution {
public:
    
    bool canMakeSubsequence(string s, string t) {
        int m = s.size(); int n = t.size();
        if(m > n) return false;
        vector<int>pre(m, n);
        int j = 0;
        for(int i = 0;i < m;i++) {
            while(j < n && s[i] != t[j]) j++;
            if(j == n) break;
            pre[i] = j;
            j++;
        }

        if(pre[m-1] < n) return true;

        vector<int>suf(m, -1);
        j = n - 1;
        for(int i = m - 1;i >= 0;i--) {
            while(j >= 0 && s[i] != t[j]) j--;
            if(j == -1) break;
            suf[i] = j;
            j--;
        }

        for(int i = 0;i < m;i++) {
            if((i == 0 || pre[i-1] != n) && (i == m - 1 || suf[i+1] != -1)) {
                int left = (i == 0) ? -1 : pre[i-1];
                int right = (i == m - 1) ? n : suf[i+1];
                if(right - left > 1) return true;
            }
        }
        return false;
    }
};
