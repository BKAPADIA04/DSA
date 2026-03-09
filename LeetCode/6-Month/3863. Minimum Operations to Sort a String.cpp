class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string temp = s;
        sort(temp.begin(), temp.end());
        if(temp == s) return 0;
        if(n == 2) return -1;

        char mini = temp[0]; char maxi = temp[n-1];
        if(mini == s[0] || maxi == s[n-1]) return 1;

        if(maxi == s[0] && mini == s[n-1]) {
            for(int i = 1;i < n - 1;i++) {
                if(s[i] == mini || s[i] == maxi) return 2;
            }
            return 3;
        }
        return 2;
    }
};
