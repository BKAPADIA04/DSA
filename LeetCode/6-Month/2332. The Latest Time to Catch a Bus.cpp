class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int n = buses.size();
        int m = passengers.size();

        int ans = 0;
        for(int i = 0, j = 0;i < n;i++) {
            int cnt = 0;
            while(j < m && cnt < capacity && passengers[j] <= buses[i]) {
                j++;
                cnt++;
            }

            if(i == (n - 1)) {
                if(cnt < capacity) {
                    int t = buses[i];
                    for(int k = j - 1; k >= 0 && passengers[k] == t;k--,t--);
                    ans = max(ans, t);
                }
                else {
                    int t = passengers[j-1] - 1;
                    for(int k = j - 2; k >= 0 && passengers[k] == t;k--,t--);
                    ans = max(ans, t);
                }
            }
        }

        return ans;
    }
};
