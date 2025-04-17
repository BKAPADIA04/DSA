class Solution {
public:
  vector<int> finalPrices(int n, vector<int> price, int q, vector<vector<int>> queries) {
    <vector<int>> queries) {
    vector<pair<int,int>>v;
    int maxi = INT_MIN;
    for(auto it:queries){
        if(it[0]==2){
            maxi = max(maxi,it[1]);
        }
        else if(it[0]==1){
            v.push_back({it[1]-1,it[2]});
        }
        
    }
    vector<int>res(n,-1);
    for(auto it:v){
        res[it.first] = it.second;
    }
    for(int i=0;i<n;i++){
        if(res[i]<maxi){
            res[i] = maxi;
        }
    }
    
    return res;
    
  }
  }
};
