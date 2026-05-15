#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll n = nums.size();
        unordered_map<int,int>freq;
        ll sum = 0ll;
        for(int i = 0;i < n;i++) {
            int num = nums[i];
            vector<int>factors;
            for(int j = 1; j <= sqrt(num);j++) {
                if(((num % j) == 0)) {
                    if(freq.find(j) != freq.end()) {
                        factors.push_back(j);
                    }

                    if(j != (num/j)) {
                        if(freq.find(num/j) != freq.end()) {
                            factors.push_back(num/j);
                        }
                    }
                }
            }
            sort(factors.begin(), factors.end());
            if(factors.empty()) { sum = sum + num; freq[num]++;}
            else { sum = sum + factors[0]; freq[factors[0]]++; }
        }

        return sum;
    }
};
