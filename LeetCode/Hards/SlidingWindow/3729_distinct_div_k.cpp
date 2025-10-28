#define ll long long
class Solution {
public:

    vector<ll>preSum;
    unordered_map<ll,ll>freqMap;

    long long numGoodSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();
        preSum = vector<ll>(n + 1,0);
        for(ll i = 1;i <= n;i++) {
            preSum[i] = preSum[i-1] + nums[i-1];
            freqMap[nums[i-1]]++;
        }

        unordered_map<ll,ll>preMap, tempMap;
        ll answer = 0ll;
        for(ll i = n - 1;i >= 0;i--) {
            if(i + 1 < n && nums[i] != nums[i+1]) {
                for(auto it : tempMap) {
                    preMap[it.first] += it.second;
                }
                tempMap.clear();
            }

            answer += preMap[preSum[i] % k];
            tempMap[preSum[i+1] % k]++;
        }

        for(auto it : freqMap) {
            ll sum = 0ll;
            while(it.second--) {
                sum += it.first;
                if(sum % k == 0) answer++;
            }
        }
        return answer;
    }
};
