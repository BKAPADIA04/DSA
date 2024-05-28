#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int j = 0;int ans = INT_MIN;
        for(int i = 0;i < n;i++) {
            if(prices[i] < prices[j]) {
                j = i;
            }
            else {
                ans = max(ans,prices[i] - prices[j]);
            }
        }
        return ans;
    }
};