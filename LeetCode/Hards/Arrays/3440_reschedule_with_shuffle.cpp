class Solution {
public:
    void print(vector<int>ans) {
        for(auto it:ans) cout << it << " ";
        cout << endl;
    }

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>free;
        int n = startTime.size();
        free.push_back(startTime[0]);
        for(int i = 1;i < n;i++) {
            free.push_back(startTime[i] - endTime[i-1]);
        }
        free.push_back(eventTime - endTime[n-1]);

        vector<int>preMax(n+1),sufMax(n+1);

        for(int i = 1;i <= n;i++) {
            preMax[i] = max(preMax[i-1],free[i-1]);
        }
        for(int i = n - 1;i >= 0;i--) {
            sufMax[i] = max(sufMax[i+1],free[i+1]);
        }
        // print(free);
        // print(preMax); print(sufMax);
        int ans = preMax[n];

        for(int i = 1;i <= n;i++) {
            int length = endTime[i-1] - startTime[i-1];
            if(length <= preMax[i-1] || length <= sufMax[i]) {
                ans = max(ans,free[i] + free[i-1] + length);
            }
            else {
                ans = max(ans,free[i] + free[i-1]);
            }
        }
        return ans;
    }
};
