class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>v;
        vector<int>maxRightReach(n + 1);
        for(int i = 0;i <= n;i++) {
            int low = max(0,i - ranges[i]);
            int high = min(n, i + ranges[i]);
            v.push_back({low,high});
            maxRightReach[low] = max(maxRightReach[low],high);
        }
        
        int maxRight = 0;
        int prev = 0;
        int answer = 0;
        for(int i = 0;i < n;i++) {
            maxRight = max(maxRight, maxRightReach[i]);

            if(maxRight <= i) return -1;

            if(i == prev) {
                answer++;
                prev = maxRight;
            }
        }
        return answer;
    }
};
