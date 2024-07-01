#include <bits/stdc++.h>
using namespace std;


// TLE
// void generate(bool * check,vector<int> &a,int i,int n ,int k,vector<int>&solve) {
//     if(i == n) {
//         if(!solve.empty() && accumulate(solve.begin(),solve.end(),0) == k) {
//             * check = true;
//         }
//         return;
//     }
//     cout << i << " " << accumulate(solve.begin(),solve.end(),0) << " " << *check << endl;
//     if(!solve.empty() && accumulate(solve.begin(),solve.end(),0) == k) {
//         * check = true;
//         return;
//     }
//     solve.push_back(a[i]);
//     generate(check,a,i+1,n,k,solve);
//     solve.pop_back();
//     generate(check,a,i+1,n,k,solve);
// }


// bool isSubsetPresent(int n, int k, vector<int> &a)
// {
//     bool ans = false;
//     bool * check = &ans;
//     * check = false;
//     vector<int>solve;
//     generate(check,a,0,n,k,solve);
//     return *check;
// }

void generate(bool * check,vector<int>&a,int i,int k,vector<int>&solve,int sum) {
    int n = a.size();
    if(i == n) {
        if(sum == k) {
            *check = true;
            // cout << "Index: " << i << ", Current Sum: " << sum << ", Check: " << * check << endl;
            return;
        }
        return;
    }

    // cout << "Index: " << i << ", Current Sum: " << sum << ", Check: " << * check << endl;
    if(sum == k) {
        *check = true;
        return;
    }
    
    if (*check) return;

    solve.push_back(a[i]);
    generate(check,a,i+1,k,solve,sum + a[i]);

    solve.pop_back();
    generate(check,a,i+1,k,solve,sum);
}



bool isSubsetPresent(int n, int k, vector<int> &a)
{
    bool ans = false;
    bool * check = &ans;
    * check = false;
    vector<int>solve;
    generate(check,a,0,k,solve,0);
    return *check;
}



int main() {
    vector<int>a = {1,2,3,4,5};
    int k = 11;
    cout << isSubsetPresent(a.size(),k,a);
}