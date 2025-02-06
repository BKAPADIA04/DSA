//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
  void print(vector<int>v) {
      for(auto it:v) cout << it << " ";
      cout << endl;
  }
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>lis_arr;
        for(int i = 0;i < n;i++) {
            auto it = lower_bound(lis_arr.begin(),lis_arr.end(),arr[i]);
            if(it == lis_arr.end()) {
                lis_arr.push_back(arr[i]);
            }
            else {
                *it = arr[i];
            }
        }
        // print(lis_arr);
        return lis_arr.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends