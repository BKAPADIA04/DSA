#define ll long long
class Solution {
public:
    long long maximumPoints(vector<int>& nums, int currentEnergy) {
        ll sum = accumulate(nums.begin(),nums.end(),0ll);
        ll mini = *min_element(nums.begin(),nums.end());

        if(currentEnergy < mini) return 0;
        ll totalEnergy = currentEnergy + sum;
        totalEnergy -= mini;

        return totalEnergy/mini;
    }
};
