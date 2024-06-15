#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}


double findSmallestMaxDist(vector<int> &nums, int k) {
    // Code here
    int n = nums.size();
    double low = 0;
    double high = INT_MIN;
    for(int i = 0;i < n - 1;i++) {
        if(nums[i+1] - nums[i] > high) {
            high = nums[i+1] - nums[i];
        }
    }
    double diff = 1e-6;
    double result;
    while (high - low > diff)
    {
        double mid = (low + high) / 2;
        int check = numberOfGasStationsRequired(mid,nums);
        if(check > k) {
            low = mid;
        }
        else {
            result = mid;
            high = mid;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {3,6,12,19,33,44,67,72,89,95};
    int k = 2;
    double ans = findSmallestMaxDist(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}