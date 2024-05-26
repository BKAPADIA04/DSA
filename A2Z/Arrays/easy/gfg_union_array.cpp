#include <bits/stdc++.h>

using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int>ans;
    //Your code here
    //return vector with correct order of elements
    int i = 0; int j = 0;
    while(i < n && j < m) {
        // if(arr1[i] == arr2[j]) {
        //     ans.push_back(arr1[i]);
        //     i++;j++;
        // }
        if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }
        else {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    if(i == n) {
        for(int k = j;k < m;k++) {
            ans.push_back(arr2[k]);
        }
    }
    if(j == m) {
        for(int k = i;k < n;k++) {
            ans.push_back(arr1[k]);
        }
    }
    // for(int i = 0;i<ans.size();i++) {
    //     cout << ans[i] << " ";
    // }
    int k = 0; 

    for (int l = 1; l < ans.size(); l++) {
        if (ans[l] != ans[k]) {
            k++;
            ans[k] = ans[l];
        }
    }
    ans.erase(ans.begin() + k + 1,ans.end());
    return ans;
}

int main() {
    int arr1[] = {2, 2, 3, 4, 5};
    int arr2[] = {1, 1, 2, 3, 4};
    vector<int>ans = findUnion(arr1,arr2,5,5);
    for(int i = 0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }   
}
