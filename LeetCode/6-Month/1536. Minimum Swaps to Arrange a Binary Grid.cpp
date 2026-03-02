class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zeroes(n);
        for(int i = 0;i < n;i++) {
            int cnt = 0;
            for(int j = n - 1;j >= 0;j--) {
                if(grid[i][j] == 0) {
                    cnt++;
                }
                else break;
            }
            zeroes[i] = cnt;
        }

        int answer = 0;

        for(int i = 0;i < n;i++) {
            int zeroNeeded = n - 1 - i;
            int j = i;
            while(j < n && zeroNeeded > zeroes[j]) j++;
            if(j == n) return -1;
            while(j > i) {
                swap(zeroes[j], zeroes[j-1]);
                j--;
                answer++;
            }
        }
        return answer;
    }
};
