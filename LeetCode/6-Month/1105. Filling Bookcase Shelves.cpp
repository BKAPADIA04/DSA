#define ll long long
class Solution {
public: 

    vector<vector<int>> books; 
    int shelfWidth;
    int n;

    vector<ll>dp;

    ll check(ll index) {
        if(index >= n) return 0ll;
        
        if(dp[index] != -1) return dp[index];
        ll ans = INT_MAX;

        ll maxi = 0ll;
        ll width = 0ll;
        for(ll i = index;i < n;i++) {
            width += books[i][0];
            maxi = max(maxi, (ll)books[i][1]);
            if(width <= shelfWidth) {
                ans = min(ans, maxi + check(i + 1));
            }
        }
        return dp[index] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->books = books;
        this->shelfWidth = shelfWidth;
        n = books.size();
        dp = vector<ll>(n,-1ll);

        return check(0);
    }
};
