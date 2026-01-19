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
};
