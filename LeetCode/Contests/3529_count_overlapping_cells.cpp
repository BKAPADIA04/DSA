class Solution {
public:

    map<pair<int,int>,int>mp;
    map<pair<int,int>,int>mp1;
    
    void print(map<pair<int,int>,int>mp) {
        for(auto it : mp) {
            cout << it.first.first << " " << it.first.second << endl;
        }
    }
    
    vector<int>kmpAlgo(string &str) {
        int n = str.size();
        vector<int>kmp(n,0);
        for(int i = 1; i < n;i++) {
            int prev_index = kmp[i - 1];
            while(prev_index > 0 && str[prev_index] != str[i]) prev_index = kmp[prev_index - 1];
            kmp[i] = prev_index + (str[i] == str[prev_index] ? 1 : 0);
        }
        return kmp;
    }
    
    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size();
        int n = grid[0].size();

        string str1 = "", str2 = "";
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                str1.push_back(grid[i][j]);
            }
        }
        
        for(int j = 0;j < n;j++) {
            for(int i = 0;i < m;i++) {
                str2.push_back(grid[i][j]);
            }
        }
        

        string temp1 = pattern + "#" + str1;
        string temp2 = pattern + "#" + str2;

        vector<int>kmp1 = kmpAlgo(temp1);

        vector<int>kmp2 = kmpAlgo(temp2);
        
        int patternLen = pattern.size();
        int i = kmp1.size() - 1; int count = patternLen;
        while(i >= patternLen) {
            if(kmp1[i] == patternLen) {
                count = 0;
            }
            if(count < patternLen) {
                count++;
                int temp = i - patternLen - 1;
                mp[{temp / n, temp % n}] = 1;
            }
            i--;
        }

        int answer = 0;
        i = kmp2.size() - 1; count = patternLen;
        while(i >= patternLen) {
            if(kmp2[i] == patternLen) {
                count = 0;
            }
            if(count < patternLen) {
                count++;
                int temp = i - patternLen - 1;
                if(mp1.find({temp % m,temp / m}) != mp1.end()) continue;
                mp1[{temp % m, temp / m}] = 1;
                if(mp.find({temp % m,temp / m }) != mp.end()) answer++;
            }
            i--;
        }
        
        return answer;
        
    }
};/*class Solution {
public:
    vector<int> getLPS(string &s, int n) {
        vector<int> LPS(n);
        for(int i = 1; i < n; i++) {
            int j = LPS[i - 1];
            while(j > 0 && s[i] != s[j]) {
                j = LPS[j - 1];
            }
            if(s[i] == s[j]) j++;
            LPS[i] = j;
        }
        
        return LPS;
    }
     
    int countCells(vector<vector<char>> &grid, string pattern) {
        int n = grid.size(), m = grid[0].size(), sz = pattern.size();
        
        string horizontalString = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                horizontalString += grid[i][j];
            }
        }
        
        string verticalString = "";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                verticalString += grid[j][i];
            }
        }
        
        string horizontalPatternString = pattern + "#" + horizontalString;
        vector<int> lps1 = getLPS(horizontalPatternString, horizontalPatternString.size());
        
        string verticalPatternString = pattern + "#" + verticalString;
        vector<int> lps2 = getLPS(verticalPatternString, verticalPatternString.size());

        // Creating the scan1 and scan2 arrays to use sweep line counting technique.
        int sz1 = lps1.size();
        vector<int> scan1(sz1 + 1);
        for(int i = 0; i < sz1; i++) {
            if(lps1[i] == sz) {
                scan1[i - sz + 1]++;
                scan1[i + 1]--;
            }
        }
        
        int sz2 = lps2.size();
        vector<int> scan2(sz2 + 1);
        for(int i = 0; i < sz2; i++) {
            if(lps2[i] == sz) {
                scan2[i - sz + 1]++;
                scan2[i + 1]--;
            }
        }
        
        vector<vector<bool>> visited(n, vector<bool> (m));
        
        // In the sweep line technique, we maintain a counter variable. At each index, we add the value of scan[i] to the counter. 
        // If the counter becomes greater than 0 after the update, it indicates that the current index is covered by at least one active range.
        int count1 = 0;
        for(int i = 0; i < sz1; i++) {
            count1 += scan1[i];
            if(count1 > 0) {
                // Here, idx = i - sz - 1 because our horizontalPatternString = pattern + "#" + horizontalString, 
                // So here we are decresing the index by sz (length of pattern) and by 1 for ("#").
                int idx = i - sz - 1;
                int row = idx / m, column = idx % m;
                visited[row][column] = true;
            }
        }
        
        int count2 = 0;
        int ans = 0;
        for(int i = 0; i < sz2; i++) {
            count2 += scan2[i];
            if(count2 > 0) {
                int idx = i - sz - 1;
                int row = idx % n, column = idx / n;

                // Increasing the ans only if the current cell is already visited while processing horizontalString.
                if(visited[row][column]) ans++;
            }
        }
        
        return ans;
    }
};*/
