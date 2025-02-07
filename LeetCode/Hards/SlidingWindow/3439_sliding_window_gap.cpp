class Solution {
public:

    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>free;
        free.push_back(startTime[0]);
        for(int i = 1;i < n;i++) {
            free.push_back(startTime[i] - endTime[i-1]);
        }
        free.push_back(eventTime - endTime[n-1]);

        int l = 0; int r = 0; int sum = 0; int maxi = 0;
        while(r < free.size()) {
            sum += free[r];

            if(r - l + 1 > k + 1) {
                sum -= free[l];
                l++;
            }
            maxi = max(maxi,sum);
            r++;
        }
        return maxi;
    }
};
