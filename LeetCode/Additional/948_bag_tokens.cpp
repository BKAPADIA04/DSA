class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int left = 0; int right = n - 1;
        int score = 0; int maxi = 0;
        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
            }
            else {
                if(score < 1) return maxi;
                power += tokens[right];
                right--;
                score--;
            }
            maxi = max(maxi,score);
        }
        return maxi;
    }
};
