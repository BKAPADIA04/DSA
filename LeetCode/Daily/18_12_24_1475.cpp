class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        // int i = 0; int j = 1;
        vector<int>ans(n,0);
        for(int i = 0;i < n;i++) {
            int j; int flag = 0;
            for(j = i+1;j < n;j++) {
                if(prices[j] <= prices[i]) {
                    ans[i] = prices[i] - prices[j]; flag = 1;break;
                }
            }
            if(flag == 0) ans[i] = prices[i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         // Create a copy of prices array to store discounted prices
//         vector<int> result = prices;

//         stack<int> stack;

//         for (int i = 0; i < prices.size(); i++) {
//             // Process items that can be discounted by current price
//             while (!stack.empty() && prices[stack.top()] >= prices[i]) {
//                 // Apply discount to previous item using current price
//                 result[stack.top()] -= prices[i];
//                 stack.pop();
//             }
//             // Add current index to stack
//             stack.push(i);
//         }

//         return result;
//     }
// };