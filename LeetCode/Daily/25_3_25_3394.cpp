class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& nums) {
        int m = nums.size();
        vector<vector<int>>numsY,numsX;
        for(int i = 0;i < m;i++) {
            numsY.push_back({nums[i][1],nums[i][3]});
            numsX.push_back({nums[i][0],nums[i][2]});
        }
        sort(numsY.begin(),numsY.end());
        sort(numsX.begin(),numsX.end()); 

        vector<vector<int>>tempY;
        for(int i = 0;i < numsY.size();i++) {
            if(tempY.size() == 0 || (numsY[i][0] >= tempY.back()[1])) {
                tempY.push_back(numsY[i]);
            }
            else {
                tempY.back()[1] = max(tempY.back()[1],numsY[i][1]);
            }
        }
        vector<vector<int>>tempX;
        for(int i = 0;i < numsX.size();i++) {
            if(tempX.size() == 0 || numsX[i][0] >= tempX.back()[1]) {
                tempX.push_back(numsX[i]);
            }
            else {
                tempX.back()[1] = max(tempX.back()[1],numsX[i][1]);
            }
        }
        return tempY.size() > 2 || tempX.size() > 2;
    }
};
