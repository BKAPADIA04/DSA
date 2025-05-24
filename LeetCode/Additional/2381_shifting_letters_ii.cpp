class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int m = shifts.size();
        vector<int>sweep(n+1,0);
        for(int i = 0;i < m;i++) {
            if(shifts[i][2] == 0) {
                sweep[shifts[i][0]]--;
                sweep[shifts[i][1] + 1]++;
            }
            else {
                sweep[shifts[i][0]]++;
                sweep[shifts[i][1] + 1]--;
            }
        }
        vector<int>preSum(n+1,0);
        preSum[0] = sweep[0];
        for(int i = 1;i < sweep.size();i++) {
            preSum[i] = (preSum[i-1] + sweep[i]) % 26;
        }

        string answer;
        for(int i = 0;i < n;i++) {
            int move = preSum[i];
            char ch;

            move %= 26;
            int chh = s[i] + move;
            if(chh > 122) chh -= 26;
            if(chh < 97) chh += 26;
            ch = (char)chh;
            answer.push_back(ch);
        }
        return answer;
    }
};
