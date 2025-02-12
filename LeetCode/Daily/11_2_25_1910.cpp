class Solution {
public:


    // O(n * m)
    // bool check(stack<char>st,string part,int m) {
    //     stack<char>tempo = st;
    //     for(int i = m - 1;i >= 0;i--) {
    //         if(!st.empty()) {
    //             if(st.top() != part[i]) return false;
    //             st.pop();
    //         }
    //     }
    //     return true;
    // }

    // string removeOccurrences(string s, string part) {
    //     int n = s.size(); int m = part.size();
    //     stack<char>st;
    //     for(int i = 0;i < n;i++) {
    //         st.push(s[i]);

    //         if(st.size() >= part.size() && check(st,part,m)) {
    //             for(int j = 0;j < part.size();j++) st.pop();
    //         }
    //     }

    //     string ans = "";
    //     while(!st.empty()) {
    //         ans = st.top() + ans;
    //         st.pop();
    //     }
    //     return ans;
    // }

    // O(n + m)

    vector<int>kmp_lps(string str) {
        int n = str.size();
        vector<int>lps(n,0);
        for(int i = 1;i < n;i++) {
            int prev_index = lps[i-1];

            while(prev_index > 0 && str[prev_index] != str[i]) prev_index = lps[prev_index - 1];

            lps[i] = prev_index + (str[i] == str[prev_index]);
        }
        return lps;
    }

    string removeOccurrences(string s, string part) {
        int n = s.size(); int m = part.size();
        vector<int>kmp = kmp_lps(part);
        string ans;
        vector<int>preIndexes; int counter = 0;
        for(int i = 0;i < n;i++) {
            ans.push_back(s[i]);
            int prev_index = preIndexes.empty() ? 0 : preIndexes.back();

            while(prev_index > 0 && part[prev_index] != s[i]) prev_index = kmp[prev_index - 1];

            if(part[prev_index] == s[i]) prev_index++;

            preIndexes.push_back(prev_index);

            if(prev_index == m) {
                ans.resize(ans.size() - part.size());
                preIndexes.resize(preIndexes.size() - part.size());
            }
        }
        return ans;
    }
};
