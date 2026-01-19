class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        int freq = 0;

        for(int i = 0;i < n;i++) {
            if(s[i] == letter) freq++;
        }
        
        string st;

        for(int i = 0;i < n;i++) {
            while(!st.empty() && (st.back() > s[i]) && (st.size() + n - i > k) && (st.back() != letter || freq > repetition)) {
                if(st.back() == letter) repetition++;
                st.pop_back();
            }   

            // cout << s[i] << " " << repetition << " " << k - st.size() << endl;

            if(st.size() < k) {
                if(s[i] == letter) {
                    st.push_back(s[i]);
                    repetition--;
                }
                else if(k - (int)st.size() > repetition) {
                    // cout << i << " " << ":bc"<< endl;
                    st.push_back(s[i]);
                }
            }
            // cout << st << endl; 
            if(s[i] == letter) freq--;
        }
        return st;
    }
};

//     string smallestSubsequence(string s, int k, char target, int reps) {
//     int N = s.length(), remain = count(s.begin(), s.end(), target);
//     string stack;

//     for (int i = 0; i < N; i++) {
//         while (!stack.empty() && stack.back() > s[i] && (N - i + stack.length() > k) && (stack.back() != target || remain > reps)) {
//             if (stack.back() == target)
//                 reps++;
//             stack.pop_back();
//         }

//         if (stack.length() < k) {
//             if (s[i] == target || k - (int)stack.length() > reps) {
//                 stack += s[i];
//                 if (s[i] == target)
//                     reps--;
//             }
//         }

//         if (s[i] == target)
//             remain--;
//     }
//     return stack;
// }


// class Solution {
// public:

//     string smallestSubsequence(string s, int k, char letter, int rep) {
//         int n = s.length();
//         vector<int> cnt(n); 
//         cnt[n-1] = (s[n-1]==letter);
//         for(int i=n-2; i>=0; --i) cnt[i] = cnt[i+1] + (s[i]==letter);
//         vector<deque<int>> ind(26);
//         for(int i=0; i<n; ++i) ind[s[i]-'a'].push_back(i);
        
        
//         int x = rep, lastInd=-1;
//         string ans = "";
//         for(int j=0; j<k; ++j){
//             for(int ch=0; ch<26; ++ch){
//                 auto &dq = ind[ch];
//                 while(dq.size() && dq.front() <= lastInd) dq.pop_front();
//                 if(!dq.size()) 
//                 continue;
//                 auto index = dq.front();
//                 if(ans.length() + n-index >= k && cnt[index] >= x && (x-(ch+'a'==letter)+j+1 <= k)){
//                     ans += ch+'a';
//                     if(ch+'a'==letter) x--;   
//                     lastInd = index;  
//                     dq.pop_front();
//                     break;
//                 }

//             }
//         }
        
//         return ans;
//     }




// };
