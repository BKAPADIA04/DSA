#define ll long long
class Solution {
public:

    void print(vector<ll>&dp) {
        for(auto it:dp) cout << it << " ";
        cout << endl;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string S = to_string(n);
        ll length = S.size();
        ll digitSize = digits.size();

        vector<ll>dp(length+1,0);
        dp[length] = 1;
        for(ll i = length - 1;i >= 0;i--) {
            ll number = S[i] - '0';
            for(ll j = 0;j < digitSize;j++) {
                if(stol(digits[j]) < number) dp[i] += pow(digitSize,length - 1 - i);
                else if(stol(digits[j]) == number) dp[i] += dp[i+1];
            }
        }

        for (int i = 1; i < length; i++)
            dp[0] += pow(digitSize, i);
        
        return dp[0];
    }
};
