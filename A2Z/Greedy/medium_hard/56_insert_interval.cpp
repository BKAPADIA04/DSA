class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int m = intervals[0].size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i = 0;i < n;i++) {
            // current interval does not merge
            if(ans.empty() || ( intervals[i][0] > ans.back()[1])) 
                ans.push_back(intervals[i]);
            else 
                // merging case
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
        return ans;
    }
