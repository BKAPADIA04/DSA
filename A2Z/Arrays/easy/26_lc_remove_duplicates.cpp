#include <bits/stdc++.h>
using namespace std;

// O(n2)
vector<int> removeDuplicates(vector<int>& nums) {
    vector<int>index;
    int i = 0;int j = 0;
    index.push_back(nums[0]);
    for(int k = 0;k < nums.size();k++) {
        while(nums[j] == nums[i] && j < nums.size()) {
            j++;
            // cout << j << endl;
        }
        k = j;i = j;
        // cout << "i - " << i << endl;
        if( i < nums.size())
            index.push_back(nums[i]);
        // cout << "i - " << i << endl;
        // k = j;i = j;
        // cout << "i - " << i << endl;
    }
    for(int i=0;i<index.size();i++) {
        nums[i] = index[i];
    }
    return index;
}

// O(n)
int removeDuplicates_Opt(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int j = 0; // Pointer to place the next unique element
    
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
    return j + 1;
}
int main() {
    int arr[] = {1,1,2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    vector<int> nums(arr, arr + n); 
    for(int i:removeDuplicates(nums)) {
        cout << i << endl;
    }
    cout << removeDuplicates_Opt(nums)<<endl;
}