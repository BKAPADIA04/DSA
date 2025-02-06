//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    void print(vector<int>dp) {
        for(auto it:dp) cout << it << " ";
        cout << endl;
    }
  
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>lis(n,1);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(nums[i] > nums[j] && 1 + lis[j] > lis[i]) {
                    lis[i] = 1 + lis[j];
                }
            }
        }
        vector<int>rev_num = nums;
        reverse(rev_num.begin(),rev_num.end());
        vector<int>lds(n,1);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(rev_num[i] > rev_num[j] && 1 + lds[j] > lds[i]) {
                    lds[i] = 1 + lds[j];
                }
            }
        }
        reverse(lds.begin(),lds.end());
        
        // print(lis); print(lds);
        int maxi = 0;
        for(int i = 1; i < n - 1;i++) {
            if(lis[i] == 1 || lds[i] == 1) continue;
            maxi = max(maxi,lis[i] + lds[i] - 1);
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends