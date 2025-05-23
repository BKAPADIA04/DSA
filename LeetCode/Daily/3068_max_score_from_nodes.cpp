#define ll long long
class Solution {
public:

    int n;
    vector<int>nums;
    vector<vector<ll>>dp;
    int k;

    ll check(int index, int isEven) {
        if(index >= n) {
            return isEven ? 0 : INT_MIN;
        }

        if(dp[index][isEven] != -1) return dp[index][isEven];

        ll pick = (nums[index] ^ k) + check(index+1,isEven^1);
        ll notPick = nums[index] + check(index+1,isEven);
        return dp[index][isEven] = max(pick,notPick);
    }



    long long maximumValueSum(vector<int>& arr, int k_, vector<vector<int>>& edges) {
        nums = arr;
        n = nums.size();
        k = k_;
        dp = vector<vector<ll>>(n,vector<ll>(2,-1));
        return check(0,1);
    }
};

/*class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<int> netChange;
        long long nodeSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            netChange.push_back((nums[i] ^ k) - nums[i]);
            nodeSum += 1ll * nums[i];
        }
        
        // Sort netChange in decreasing order
        sort(netChange.begin(), netChange.end(), greater<int>());
        
        for (int i = 0; i < netChange.size(); i += 2) {
            // If netChange contains odd number of elements break the loop
            if (i + 1 == netChange.size()) {
                break;
            }
            long long pairSum = netChange[i] + netChange[i + 1];
            
            // Include in nodeSum if pairSum is positive
            if (pairSum > 0) {
                nodeSum += pairSum;
            }
        }
        return nodeSum;
    }
};*/

/*
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0, positiveMinimum = (1 << 30),
            negativeMaximum = -1 * (1 << 30);
            
        for (int nodeValue : nums) {
            int operatedNodeValue = nodeValue ^ k;
            sum += nodeValue;
            int netChange = operatedNodeValue - nodeValue;
            
            if (netChange > 0) {
                positiveMinimum = min(positiveMinimum, netChange);
                sum += netChange;
                count++;
            } else {
                negativeMaximum = max(negativeMaximum, netChange);
            }
        }
        
        // If the number of positive netChange values is even return the sum.
        if (count % 2 == 0) {
            return sum;
        }
        
        // Otherwise return the maximum of both discussed cases.
        return max(sum - positiveMinimum, sum + negativeMaximum);
    }
};*/
