class Solution {
public:

    void print(vector<vector<int>>answer) {
        for(auto it : answer) {
            for(auto it1 : it) cout << it1 << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    int val;

    void check(vector<vector<int>>&answer, int left, int right, int up, int down) {
        if(left == right && up == down) {
            answer[up][left] = val;
            val = val + 1;
            return;
        }
        
        int mid_h = (left + right)/2;
        int mid_v = (up + down)/2;
        check(answer,mid_h + 1, right, up, mid_v);
        check(answer,mid_h + 1, right, mid_v + 1, down);
        check(answer,left, mid_h, mid_v + 1,down);
        check(answer,left, mid_h, up, mid_v);
    }

    vector<vector<int>> specialGrid(int n) {
        int row = pow(2,n);
        vector<vector<int>>answer(row,vector<int>(row,-1));
        val = 0;
        check(answer,0,row - 1,0,row - 1);
        return answer;
    }
};
