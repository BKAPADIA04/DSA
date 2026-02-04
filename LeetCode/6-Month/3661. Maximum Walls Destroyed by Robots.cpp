#define ll long long
class Solution {
public:

    vector<vector<ll>>dp;

    int wallsDestroyed(vector<int>& walls, int low, int high) {
        int left = lower_bound(walls.begin(),walls.end(),low) - walls.begin();
        int right = upper_bound(walls.begin(),walls.end(),high) - walls.begin();
        return right - left;
    }

    int check(int i, int dir, vector<int>& walls, vector<pair<ll,ll>>&robotRange,vector<pair<int,int>>&robotInfo) {
        if(i == robotRange.size()) return 0;

        if(dp[i][dir] != -1ll) return dp[i][dir];

        ll left = robotRange[i].first;
        if(dir == 1) {
            left = max(left, robotRange[i-1].second + 1);
        }

        int leftSide = wallsDestroyed(walls, left, robotInfo[i].first) + check(i+1,0,walls,robotRange,robotInfo);
        int rightSide = wallsDestroyed(walls, robotInfo[i].first, robotRange[i].second) + check(i+1,1,walls,robotRange,robotInfo);

        return dp[i][dir] = max(leftSide, rightSide);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<pair<int,int>>robotInfo;
        for(int i = 0;i < robots.size();i++) robotInfo.push_back({robots[i], distance[i]});
        sort(robotInfo.begin(), robotInfo.end());
        sort(walls.begin(), walls.end());

        vector<pair<ll,ll>>robotRange;
        for(int i = 0;i < robotInfo.size();i++) {
            if(i == 0) {
                int left = robotInfo[i].first - robotInfo[i].second;
                int right = robotInfo[i].first + robotInfo[i].second;
                if(i + 1 < robotInfo.size()) {
                    right = min(right, robotInfo[i+1].first - 1);
                } 
                robotRange.push_back({left, right});
                continue;
            }

            if(i == robotInfo.size() - 1) {
                int left = robotInfo[i].first - robotInfo[i].second;
                int right = robotInfo[i].first + robotInfo[i].second;
                if(i - 1 >= 0) {
                    left = max(left, robotInfo[i-1].first + 1);
                } 
                robotRange.push_back({left, right});
                continue;
            }

            int left = max(robotInfo[i].first - robotInfo[i].second, robotInfo[i-1].first + 1);
            int right = min(robotInfo[i].first + robotInfo[i].second, robotInfo[i+1].first - 1);
            robotRange.push_back({left, right});
        }

        int n = robotInfo.size();
        dp = vector<vector<ll>>(n,vector<ll>(2,-1ll));

        // for(auto it:robotRange) cout << it.first << " " << it.second << endl;
        return check(0,0,walls,robotRange,robotInfo);
    }
};
