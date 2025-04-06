#define ll long long
class Solution {
public:

    int n,altK,l;
    vector<int>arr;
    map<array<int,4>,int>dp;

    int check(int index, int chance, int sum,int product) {
        if(product > l) product = l + 1;
        if(index == n) {
            if(sum == altK && product <= l && chance != 0) return product;
            return -1; 
        }

        if(dp.count({index,chance,sum,product})) return dp[{index,chance,sum,product}];

        // not pick
        int notTake = check(index + 1,chance,sum,product);

        // pick
        int temp = 0; int tempSum = 0;
        if(chance == 0) { temp = 2; tempSum = arr[index]; }
        if(chance == 1) { temp = 2; tempSum = sum + arr[index]; }
        if(chance == 2) { temp = 1; tempSum = sum - arr[index]; }

        int take = check(index + 1,temp,tempSum,(ll)arr[index] * product);
        
        return dp[{index,chance,sum,product}] = max(take,notTake);
    }
 
    int maxProduct(vector<int>& nums, int k, int limit) {
        n = nums.size();
        arr = nums;
        altK = k;
        l = limit;
        int sum = min(900,accumulate(nums.begin(),nums.end(),0));
        if(-sum > k || sum < k) return -1;
        return check(0,0,0,1);
    }
};
