#include <bits/stdc++.h>
using namespace std;
// Kadane
int maxSubArray(vector<int>& nums) {
        // Kadane
        int n = nums.size();
        long long sum = 0;
        long long maxi = INT_MIN;
        for(int i = 0;i < n;i++) {
            sum += nums[i];

            maxi = max(sum,maxi);

            if(sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
int main()
{
    int arr[] = {-2,1,-3,4};
    vector<int>a(arr,arr+(sizeof(arr)/sizeof(int)));
    int len = maxSubArray(a);
    cout << len << "\n";
    return 0;
}