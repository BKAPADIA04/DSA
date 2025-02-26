#define ll long long
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        ll n = nums.size();
        ll sum = 0ll; ll maxi = 0ll;
        for(ll i = 0; i < n;i++) {
            sum += nums[i];

            maxi = max(maxi,sum);

            if(sum < 0) sum = 0;
        }

        // vector<int>tempo = nums;
        for(ll i = 0;i < n;i++) {
            nums[i] = -nums[i];
        }

        sum = 0ll;
        for(ll i = 0; i < n;i++) {
            sum += nums[i];

            maxi = max(maxi,sum);

            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};

/*
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }

        return maxPrefixSum - minPrefixSum;
    }
};
*/
