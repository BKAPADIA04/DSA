#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b){
    //complete the function here
    // pair<int,int>ans;
    // ans.first = b;
    // ans.second = a;
    // return ans;
    
    // int c = a ^ b;
    // pair<int,int>ans;
    // ans.first = c ^ a;
    // ans.second = c ^ b;
    // return ans;
    
    pair<int,int>ans;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    ans.first = a;
    ans.second = b;
    return ans;
}

