// #define ll long long
// class Solution {
// public:

//     // vector<ll>computeLCM(vector<int>&targets) {
//     //     vector<ll>preComputedLCM()
//     //     for(int i = 0;i < targets.size();i++) {
//     //         for(int j = 0;j < targets.size();j++) {

//     //         }
//     //     }
//     // }

//     int minimumIncrements(vector<int>& nums, vector<int>& target) {
//         int n = nums.size();
//         vector<vector<ll>>dp(n,vector<int>(16,-1)); // 2^4
//         vector<ll>preComputedLCM = 
//     }
// };

#define ll long long int

ll dp[50005][17], numCount, targetCount;
ll lcmPrecomputed[17];
vector<int> nums, target;

ll computeLCM(ll x, ll y) {
    return (x * y) / __gcd(x, y);
}

void precomputeLCM() {
    for (ll subset = 1; subset < (1 << targetCount); subset++) {
        lcmPrecomputed[subset] = 1;
        for (ll j = 0; j < targetCount; j++) {
            if (subset & (1 << j)) {
                lcmPrecomputed[subset] = computeLCM(lcmPrecomputed[subset], target[j]);
            }
        }
    }
}

ll findMinOperations(ll i, ll mask) {
    if (mask == (1 << targetCount) - 1) return 0;
    if (i == numCount) return 1e9;
    if (dp[i][mask] != -1) return dp[i][mask];

    ll minOperations = 1e9;
    minOperations = min(minOperations, findMinOperations(i + 1, mask));

    for (ll subset = 1; subset < (1 << targetCount); subset++) {
        ll subsetLCM = lcmPrecomputed[subset];
        ll nextMultiple = (ll)ceil((double)nums[i] / subsetLCM) * subsetLCM;
        minOperations = min(minOperations, (nextMultiple - nums[i]) + findMinOperations(i + 1, mask | subset));
    }

    return dp[i][mask] = minOperations;
}

class Solution {
public:
    int minimumIncrements(vector<int>& inputNums, vector<int>& inputTarget) {
        nums = inputNums;
        target = inputTarget;
        numCount = nums.size();
        targetCount = target.size();

        memset(dp, -1, sizeof(dp));
        memset(lcmPrecomputed, 0, sizeof(lcmPrecomputed));

        precomputeLCM();
        return findMinOperations(0, 0);
    }
};
