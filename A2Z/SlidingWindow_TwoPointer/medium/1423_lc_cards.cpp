#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& v, int k) {
    int n = v.size();
    int lsum = 0,rsum = 0;
    
    for(int i = 0;i < k;i++) {
        lsum += v[i];
    }
    int answer = lsum;
    int minLength = n - 1;
    for(int i = k-1;i >= 0;i--) {
        lsum -= v[i];
        rsum += v[minLength--];
        answer = max(answer,lsum + rsum);
    }   
    return answer;
}

int main() {
    vector<int>v = {96,90,41,82,39,74,64,50,30};
    int k = 8;
    cout << maxScore(v,k) << endl;
}