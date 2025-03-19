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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // int n = intervals.size();
        // if(n == 0) {
        //     return {newInterval};
        // }
        // vector<vector<int>>answer;
        // int start = newInterval[0]; int end = newInterval[1]; int i = 0;
        // int newStart = start; int newEnd = end;

        // if(end < intervals[0][0]) {
        //     answer.push_back(newInterval);
        // }

        // while(i < n) {
        //     if(i > 0 && intervals[i][0] > end && intervals[i-1][1] < start) {
        //         answer.push_back(newInterval); answer.push_back(intervals[i]); i++;
        //     }
        //     else if(intervals[i][1] < newStart || intervals[i][0] > newEnd) {
        //         answer.push_back(intervals[i]); i++;
        //     }
        //     else if(intervals[i][1] >= start) {
        //         newStart = min(start,intervals[i][0]);
        //         newEnd = max(intervals[i][1],end);
        //         for(;i < n;i++) {
        //             if(newEnd >= intervals[i][0]) {
        //                 newEnd = max(intervals[i][1],end);
        //             }
        //             else break;
        //         }
        //         answer.push_back({newStart,newEnd});
                
        //     }
        //     else {
        //         answer.push_back(newInterval);i++; 
        //     }
        // }
        // int size = answer.size();
        // if(start > answer[size-1][1]) answer.push_back(newInterval);
        // return answer;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        return merge(intervals);
    }
};
