class Solution {
public:

    vector<int>dist;
    int speed;
    int hoursBefore;
    int n;
    double precision = 1e-7;
    vector<vector<double>>dp;

    int ceilF(double x) {
        int num = (int)x;
        if(num == x) return num;
        return num + 1;
    }

    double check(int i, int skips) {
        if(i == n) return 0.0;
        if(dp[i][skips] != -1.0) return dp[i][skips];

        double time = (double)(dist[i])/ (double)(speed);
        double ans = ceilF(time + check(i+1, skips));

        if(skips > 0) {
            ans = min(ans, time + check(i+1, skips - 1) - precision);
        }
        return dp[i][skips] = ans;
    }

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        this->dist = dist;
        this->speed = speed;
        this->hoursBefore = hoursBefore;
        n = dist.size();

        int low = 0; int high = n;
        int ans = -1;
        dp = vector<vector<double>>(n,vector<double>(n + 1,-1.0));
        while(low <= high) {
            int mid = (low + high)/2;
            if(check(0,mid) <= hoursBefore) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
