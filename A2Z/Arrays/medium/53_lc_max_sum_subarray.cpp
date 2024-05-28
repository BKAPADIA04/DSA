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
void maxSubArrayPrint(vector<int>& nums) {
    // Kadane
    int n = nums.size();
    long long sum = 0;
    long long maxi = INT_MIN;
    int left = 0;int right = 0;
    if(n == 1) {cout << left << right << endl; return;}
    for(int i = 0;i < n;i++) {
        sum += nums[i];

        if(sum > maxi) {
            maxi = sum;
            right = i;
        }

        if(sum < 0) {
            sum = 0;
            left = i + 1;
        }
    }
    cout << left << right << endl;
    return;


    // or

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    cout << ansStart << ansEnd << endl;
}
int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int>a(arr,arr+(sizeof(arr)/sizeof(int)));
    int len = maxSubArray(a);
    cout << len << "\n";
    maxSubArrayPrint(a);
    return 0;
}