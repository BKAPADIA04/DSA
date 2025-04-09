class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int alice = 0; int bob = 0;
        int i = 0;
        for(int j = 1;j < n;j++) {
            if(colors[j] != colors[j - 1]) {
                int length = j - i;
                if(colors[j - 1] == 'A') {
                    alice += max(0, length - 2);
                }
                if(colors[j - 1] == 'B') {
                    bob += max(0, length - 2);
                }

                i = j;
            }
        }

        int length = n - i;
        if(colors[i] == 'A') {
            alice += max(0, length - 2);
        }
        if(colors[i] == 'B') {
            bob += max(0, length - 2);
        }
        
        return alice > bob;
    }
};
