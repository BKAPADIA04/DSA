class Solution {
public:
    // TLE
    // map<pair<int,int>,int>m;

    // vector<int>nge_(vector<int>&heights) {
    //     int n = heights.size();
    //     vector<int>answer(n,-1);
    //     answer[n - 1] = n;
    //     stack<int>st;
    //     st.push(n - 1);
    //     for(int i = n - 2;i >= 0;i--) {
    //         while(!st.empty() && heights[st.top()] <= heights[i]) {
    //             st.pop();
    //         }
    //         if(!st.empty()) {
    //             answer[i] = st.top();
    //         }
    //         else {
    //             answer[i] = n;
    //         }

    //         st.push(i);
    //     }
    //     return answer;
    // }

    // vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    //     vector<int>nge = nge_(heights);
    //     // for(auto it : nge) cout << it << " ";
    //     int n = nge.size();
    //     vector<int>answer(queries.size(),-1);
    //     for(int i = 0;i < queries.size();i++) {
    //         int start = min(queries[i][0],queries[i][1]);
    //         int end = max(queries[i][0],queries[i][1]);
    //         if(m.find({start,end}) != m.end()) {
    //             answer[i] = m[{start,end}];
    //             continue;
    //         }
    //         if(start == end) {
    //             answer[i] = end;
    //         }
    //         else if(heights[start] < heights[end]) {
    //             answer[i] = end;
    //         }
    //         else {
    //             int idx = end;
    //             while (idx < n && heights[idx] <= heights[start]) {
    //                 idx = nge[idx];
    //             }
    //             if (idx < n) answer[i] = idx;
    //         }
    //         m[{start,end}] = answer[i];
    //     }
    //     return answer;
    // }

    int binarySearch(int height, vector<pair<int,int>>&st) {
        int low = 0; int high = st.size() - 1; int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(st[mid].first > height) {
                ans = mid; 
                low = mid + 1; 
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<pair<int,int>>st;
        vector<int> answer(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());

        for(int i = 0; i < queries.size();i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if((heights[b] > heights[a]) || (a == b)) answer[i] = b;
            if(answer[i] == -1) newQueries[b].push_back({heights[a], i}); 
        }

        for(int i = n - 1; i >= 0;i--) {
            for(auto it : newQueries[i]) {
                int h = it.first; int idx = it.second;
                int pos = binarySearch(h, st);
                if(pos != -1) answer[idx] = st[pos].second;
            }

            while(!st.empty() && st.back().first <= heights[i]) {
                st.pop_back();
            }

            st.push_back({heights[i], i});
        }

        return answer;
    }
};
