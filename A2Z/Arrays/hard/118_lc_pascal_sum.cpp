#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        int ans = 1;
        if(numRows == 1) { pascal.push_back({1}); return pascal;}
        if(numRows == 2) {
            pascal.push_back({1});
            pascal.push_back({1,1});
            return pascal;
        }
        pascal.push_back({1});
        pascal.push_back({1,1});
        for(int i = 2;i < numRows;i++) {
            vector<int>temp = pascal[i-1];
            vector<int>add;
            add.push_back({1});
            for(int j = 1;j < temp.size();j++) {
                add.push_back({temp[j] + temp[j-1]});
            }
            add.push_back({1});
            pascal.push_back(add);
        }
    return pascal;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> row(i+1, 1);
            for(int j = 1; j < i; j++){
                row[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};