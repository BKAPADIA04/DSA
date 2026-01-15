class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxH = 1; int maxV = 1;
        int curH = 1; int curV = 1;

        for(int i = 1;i < hBars.size();i++) {
            if(hBars[i] == hBars[i-1] + 1) curH++;
            else curH = 1;

            maxH = max(maxH, curH);
        }
        
        for(int i = 1;i < vBars.size();i++) {
            if(vBars[i] == vBars[i-1] + 1) curV++;
            else curV = 1;

            maxV = max(maxV, curV);
        }

        int side = min(maxH, maxV) + 1;

        return side * side;
    }
};
