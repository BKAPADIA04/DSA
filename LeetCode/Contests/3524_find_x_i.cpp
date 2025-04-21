#define ll long long
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll>answer(k,0);
        vector<ll>count(k,0);

        for(ll i = 0;i < n;i++) {
            nums[i] %= k;
            vector<ll>tempCount(k,0);
            tempCount[nums[i]]++;
            for(int j = 0;j < k;j++) {
                tempCount[j * nums[i] % k] += count[j];
            }
            count = tempCount;

            for(int j = 0;j < k;j++) {
                answer[j] += count[j];
            }
        }

        return answer;
    }
};
