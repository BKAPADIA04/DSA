#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    
    static bool compare(pair<double,int>a,pair<double,int>b) {
        return a.first > b.first;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,int>>vw;
        for(int i = 0;i < n;i++) {
            vw.push_back({(arr[i].value * 1.0)/arr[i].weight,i});
        }
        sort(vw.begin(),vw.end(),compare);
    
        double answer = 0.0;
        for(int i = 0;i < n && w!=0;i++) {
            int index = vw[i].second;
            if(w - arr[index].weight >= 0) {
                answer += arr[index].value;
                w -= arr[index].weight;
            }
            else {  
                double per_quan = vw[i].first;
                answer += per_quan * w;
                w = 0;
            }
        }
        return answer;
    }
};