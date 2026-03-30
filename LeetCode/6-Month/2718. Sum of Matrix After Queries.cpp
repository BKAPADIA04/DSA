#define ll long long
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        ll sum = 0ll;
        ll remRow = n; ll remCol = n;
        vector<bool>row(n,true), col(n,true);
        for(int i = (int)queries.size() - 1;i >= 0;i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if(type == 0 && row[index]) {
                remRow--;
                sum = sum + (ll)val * (ll)remCol;
                row[index] = false;
            }
            else if(type == 1 && col[index]){
                remCol--;
                sum = sum + (ll)val * (ll)remRow;
                col[index] = false;
            }
        }

        return sum;
    }
};
