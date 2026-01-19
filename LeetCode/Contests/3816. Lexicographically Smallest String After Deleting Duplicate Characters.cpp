class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        for(int i = 0;i < n;i++) freq[s[i] - 'a']++;

        string st;
        for(int i = 0;i < n;i++) {
            while(st.size() > 0 && (st.back() > s[i]) && (freq[st.back() - 'a'] >= 2)) {
                freq[st.back() - 'a']--;
                st.pop_back();
            }
            st.push_back(s[i]);
        }
        n =st.size();
        while( n >= 2 && freq[st[n-1]-'a'] > 1){
            freq[st[n-1]-'a']--;
            st.pop_back();
            n = st.size();
        }
        
        return st;
    }
};

// class Solution {
// public:
//     string lexSmallestAfterDeletion(string s) {
//         stack<char>stk;
//         vector<int>cnt(26,0);
//         for(auto &i : s) cnt[i-'a']++;
        
//         int n = s.size();
//         for(int i= 0; i < n;i++){
//             if(stk.empty() || stk.top() <= s[i]) { stk.push(s[i]); cout << i << " " << "hi" << endl;}
//             else{
//                 while(!stk.empty() && cnt[stk.top()-'a'] >= 2 && stk.top() > s[i]){
//                     cnt[stk.top()-'a']--;
//                     stk.pop();
//                 }
//                 stk.push(s[i]);
//             }
//         }

//         string ans = "";
//         while(!stk.empty()){
//             ans += stk.top();  
//             cout << ans << endl;
//             stk.pop();
//         }

//         reverse(ans.begin(),ans.end());

//         n =ans.size();
//         while( n >= 2 && cnt[ans[n-1]-'a'] > 1){
//             cnt[ans[n-1]-'a']--;
//             ans.pop_back();
//             n = ans.size();
//         }
//         return ans;
//     }
// };
