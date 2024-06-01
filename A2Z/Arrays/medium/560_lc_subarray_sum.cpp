#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // size of the array.
        map<int, vector<int> >preSumMap;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            //calculate the prefix sum till index i:
            sum += nums[i];

            // if the sum = k, update the maxLen:
            if (sum == k) {
                count++;
            }

            // calculate the sum of remaining part i.e. x-k:
            int rem = sum - k;

            //Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end()) {
                count = count + preSumMap[rem].size();
            }

            //Finally, update the map checking the conditions:
            // if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum].push_back(i);
            // }
        }

        return count;
        }
};
