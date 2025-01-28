class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int s1 = 0; int s2 = 0;
        for(int i = 0;i < n;i++) {
            char ch = s[i];
            if(ch == '(') {
                s1++;
            }
            else if(ch == ')') {
                if(s1 > 0) s1--;
                else s2++;
            }
        }
        // cout << s1.size() << " " << s2.size() << endl;
        // return s1.size() + s2.size();
        return s1 + s2;
    }
};