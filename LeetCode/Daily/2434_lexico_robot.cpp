class Solution {
public:

    string robotWithString(string s) {
        unordered_map<char,int>freq;
        for(char ch:s) freq[ch]++;

        stack<char>st;
        string answer;
        char minCh = 'a';

        for(char ch : s) {
            st.push(ch);
            freq[ch]--;

            while(minCh != 'z' && freq[minCh] == 0) minCh++;
            while(!st.empty() && st.top() <= minCh) {
                answer.push_back(st.top());
                st.pop();
            }
        }
        return answer;
    }
};

/*class Solution {
public:
    string robotWithString(string s) {
        string p("");
        int n = s.length();
        vector<char> minChar(n+1);
        minChar[n] = 'z' + 1;
        for(int i=n-1;i>=0;i--) {
            minChar[i] = min(s[i], minChar[i+1]);
        }

        int index = 0;
        stack<char> stk;

        while((index < n) || (!stk.empty())) {
            while((!stk.empty()) && ((index >= n) || (stk.top() <= minChar[index]))) {
                p += stk.top();
                stk.pop();
            }
            if(index < n) {
                stk.push(s[index]);
                index++;
            }
        }
        return p;
    }
};*/
