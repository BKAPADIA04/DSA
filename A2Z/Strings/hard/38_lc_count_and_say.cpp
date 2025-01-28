class Solution {
public:

    string countAndSay(int n) {
       if(n == 1) return "1";

       string ans = countAndSay(n-1);
    
        string temp = ""; int j = 0; int i = 0;
       while(i < ans.size()){
            while(i < ans.size() && ans[i] == ans[j]) {
                i++;
            }
            int size = i - j;
            char ch = ans[j];
            temp += to_string(size) + ch;
            j = i;
       }
       return temp; 
    }
};