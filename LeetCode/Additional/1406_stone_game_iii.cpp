class Solution {
public:

    int N;

    vector<vector<int>>dp;

    int check(vector<int>& stoneValue, int index, int chance) {
        if(index >= N) return 0;
        if(dp[index][chance] != -1) return dp[index][chance];

        int ans = (chance == 1) ? INT_MIN : INT_MAX;
        int sum = 0;
        for(int x = 1;x <= min(3, N - index);x++) {
            sum += stoneValue[index + x - 1];
            if(chance == 1) {
                ans = max(ans, sum + check(stoneValue, index + x, 1 - chance));
            }
            else {
                ans = min(ans, -sum + check(stoneValue, index + x, 1 - chance));
            }
        }
        return dp[index][chance] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        N = stoneValue.size();
        dp = vector<vector<int>>(N + 1,vector<int>(2,-1));
        int ans = check(stoneValue, 0, 1);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};

/*

//Approach-1 (Using simple resurion + memoization)
class Solution {
public:
    int n;
    vector<int> t;
    
    int solve(vector<int>& stoneValue, int i) {
        if(i == n)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        t[i] = stoneValue[i] - solve(stoneValue, i+1);
        
        if(i+1 < n)
            t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] - solve(stoneValue, i+2));
        
        if(i+2 < n)
            t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(stoneValue, i+3));
        
        return t[i];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        t.resize(n+1, -1);
        
        int diff =  solve(stoneValue, 0);
        
        if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";
        
        return "Tie";
    }
};


//Approach-2 (Converting approach-1 to Bottom Up)
class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
       
        vector<int> t(n+1);
        //t[i] = Alice - Bob
        
        for(int i = n-1; i>=0; i--) {
            
            t[i] = stoneValue[i] - t[i+1];
            
            if(i+2 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] - t[i+2]);
        
            if(i+3 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - t[i+3]);
        
        }
        
        int diff = t[0];
        if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";
        
        return "Tie";
    }
};


//Approach-3 (Convertin Approach-2 above to constant space)
class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
       
        int a = 0;
        int b = 0;
        int c = 0;
        
        for(int i = n-1; i>=0; i--) {
            
            int result = INT_MIN;
            
            result = max(result, stoneValue[i] - b);
            
            if(i+2 <= n)
                result = max(result, stoneValue[i] + stoneValue[i+1] - b);
        
            if(i+3 <= n)
                result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - c);
            
            c = b;
            b = a;
            a = result;

        }
        
        int diff = a;
        if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";
        
        return "Tie";
    }
};


//Approach-4 (Using MiniMax Game Theory) - Similar to Stone Game-II
class Solution {
public:
    int Alice = 1; 
    int Bob = 0;
    int n;
    
    int miniMax(vector<int>& stoneValue, int player, int i, vector<vector<int>>& t) {
        if(i >= n)
            return 0;
        
        if (t[player][i] != -1) 
            return t[player][i];
        
        int result = player == Alice ? INT_MIN : INT_MAX;
        
        int stones = 0;
        
        for (int j = i; j < min(i+3, n); j++) {
            if (player == Alice) {
                stones += stoneValue[j];
                result = max(result, stones + miniMax(stoneValue, Bob, j + 1, t));
            } else {
                stones -= stoneValue[j];
                result = min(result, stones + miniMax(stoneValue, Alice, j + 1, t));
            }
        }
        return t[player][i] = result;
        
        
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<vector<int>> t(2, vector<int>(n+1, -1));
        int diff = miniMax(stoneValue, 1, 0, t);
        
        if(diff > 0)
            return "Alice";
        else if(diff < 0)
            return "Bob";
        
        return "Tie";
    }
};*/
