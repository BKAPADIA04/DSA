class Solution {
public:

    // KMP String Matching
    // Prefix that matches any substring of the string
    // Longest Suffix that matches a prefix
    // The index stands for the length as well as index(as it is related to prefix)

    void print(vector<int>v) {
        for(auto it:v) cout << it << " " ;
        cout << endl;
    }

    vector<int>kmp(string s) {
        vector<int>lps(s.size(),0);
        for(int i = 1;i < lps.size();i++) {
            int prev_index = lps[i-1];

            while(prev_index > 0 && s[prev_index] != s[i]) prev_index = lps[prev_index-1];

            lps[i] = prev_index + (s[prev_index] == s[i] ? 1 : 0);
        }
        return lps;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string sa = a + "#" + s;
        string sb = b + "#" + s;
        vector<int>va,vb;
        vector<int>v = kmp(sa);
        for(int i = a.size();i < v.size();i++) {
            if(v[i] == a.size()) {
                int index = i - 2*a.size();
                if(index >= 0) va.push_back(index);
            }
        }

        v = kmp(sb);
        for(int i = b.size();i < v.size();i++) {
            if(v[i] == b.size()) {
                int index = i - 2*b.size();
                if(index >= 0) vb.push_back(index);
            }
        }

        print(va); print(vb);

        vector<int>ans; int lower_bound_index = 0;
        if(va.size() == 0 || vb.size() == 0) return ans;
        for(int i = 0;i < va.size();i++) {
            int ele = va[i];

            lower_bound_index = lower_bound(vb.begin(),vb.end(),ele) - vb.begin();
            if(lower_bound_index != vb.size() && abs(vb[lower_bound_index] - ele) <= k) { ans.push_back(ele); continue; }
            if(lower_bound_index != 0 && abs(vb[lower_bound_index-1] - ele) <= k) ans.push_back(ele);
        }
        print(ans);
        return ans;
    }
};