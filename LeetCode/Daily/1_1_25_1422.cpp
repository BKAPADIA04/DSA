class Solution {
public:

    void print(vector<int>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }
    int maxScore(string s) {
        int n = s.size();
        vector<int>zeroes(n,0),ones(n,0);
        if(s[0] == '0') zeroes[0] = 1;
        if(s[n-1] == '1') ones[n-1] = 1;
        for(int i = 1;i < n;i++) {
            zeroes[i] = zeroes[i-1] + (s[i] == '0');
        }
        for(int i = n - 2;i >= 0;i--) {
            ones[i] = ones[i+1] + (s[i] == '1');
        }
        print(zeroes);
        print(ones);

        int maxi = -1;
        for(int i = 0;i < n-1;i++) {
            maxi = max(maxi,zeroes[i] + ones[i+1]);
        }
        return maxi;
    }
};


/*class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};*/
