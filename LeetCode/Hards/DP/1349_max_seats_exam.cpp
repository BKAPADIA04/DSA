class Solution {
public:
    int rows; int cols;
    vector<int>validSeats;

    int check(vector<vector<int>>&dp,int seatMask,int row) {
        if(dp[seatMask][row] != -1) return dp[seatMask][row];
        int maxi = 0;
        for(int mask = 0; mask < (1 << cols); mask++) {
            if ((seatMask | mask) != seatMask || (mask & (mask << 1)) != 0) {
                // first term - ensures that the given arrangement of students is allowed
                // second term - ensures no two consecutive ones present
                continue;
            }

            int count = __builtin_popcount(mask);
            if(row == rows - 1) {
                maxi = max(maxi,count);
            }
            else {
                int nextValidSeats = validSeats[row + 1];
                nextValidSeats &= ~(mask << 1);
                nextValidSeats &= ~(mask >> 1);
                maxi = max(maxi,count + check(dp,nextValidSeats,row + 1));
            }
        }
        return dp[seatMask][row] = maxi;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(); int m = seats[0].size();
        rows = n; cols = m;
        vector<int>bitmask(n,0);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(seats[i][j] == '.') bitmask[i] |= (1 << j);
            }
        }
        validSeats = bitmask;
        vector<vector<int>> dp(1 << m, vector<int>(n, -1));
        return check(dp,bitmask[0],0);
    }
};
