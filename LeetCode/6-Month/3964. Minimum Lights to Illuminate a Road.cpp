class Solution {
public:

    vector<pair<int,int>>merged(vector<pair<int,int>>intervals) {
        vector<pair<int,int>>answer;
        for(int i = 0;i < (int)intervals.size();i++) {
            if(answer.empty() || answer.back().second < intervals[i].first) {
                answer.push_back(intervals[i]);
            }
            else {
                answer.back().second = max(answer.back().second, intervals[i].second);
            }
        }

        return answer;
    }
    
    int minLights(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>intervals;
        for(int i = 0;i < n;i++) {
            if(nums[i] == 0) continue;
            int s = max(0, i - nums[i]);
            int e = min(n - 1, i + nums[i]);
            intervals.push_back({s, e});
        }

        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>>mergedNums = merged(intervals);
        // for(auto it : mergedNums) cout << it.first << " " << it.second << endl;
        int start = 0; 
        int ans = 0;
        for(int i = 0;i < (int)mergedNums.size();i++) {
            int gap = mergedNums[i].first - start;
            // cout << gap << endl;
            if(gap > 0) {
                ans += (gap + 2)/3;
            }

            start = mergedNums[i].second + 1;
        }

        if(n - start > 0) {
            int gap = n - start;
            ans += (gap + 2)/3;
        }

        return ans;
    }
};
