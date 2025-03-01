class Solution {
public:

    bool check(string s,int counter,int index,vector<vector<int>>&dp) {
        int n = s.size();
        if(index >= n) {
            return counter == 0;
        }
        if(counter < 0) return 0;
        // cout << index << " " << counter << endl;
        if(dp[index][counter] != -1) return dp[index][counter];
 
        bool ans = false;
        if(s[index] == '(') {
            ans = ans | check(s,counter+1,index+1,dp);
        }
        else if(s[index] == ')') {
            ans = ans | check(s,counter-1,index+1,dp);
        }
        else {
            ans = ans | check(s,counter+1,index+1,dp) | check(s,counter-1,index+1,dp) | check(s,counter,index+1,dp);
        }
        return dp[index][counter] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        // vector<vector<int>>dp(n,vector<int>(10000,-1));
        // return check(s,0,0,dp);

        stack<int>openBrackets; stack<int>asterisks;
        for(int i = 0;i < n;i++) {
            if(s[i] == '(') openBrackets.push(i);
            if(s[i] == '*') asterisks.push(i);

            if(s[i] == ')') {
                if(!openBrackets.empty()) openBrackets.pop();
                else if(!asterisks.empty()) asterisks.pop();
                else return false;
            }
        }
        
        while(!openBrackets.empty() && !asterisks.empty()) {
            if(openBrackets.top() > asterisks.top()) return false;
            openBrackets.pop();
            asterisks.pop();
        }
        return openBrackets.empty();
    }
};

/* Most Optimal
class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;
        
        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= length; i++) {
            // Count open parentheses or asterisks
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            // Count close parentheses or asterisks
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
        // If open count and close count are both non-negative, the string is valid
        return true;
    }
};*/
