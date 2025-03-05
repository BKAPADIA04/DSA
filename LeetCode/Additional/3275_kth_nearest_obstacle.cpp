class Solution {
public:
    // vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    //     multiset<int>s;
    //     vector<int>answer;
    //     for(int i = 0;i < queries.size();i++) {
    //         int dist = abs(queries[i][0]) + abs(queries[i][1]);
    //         if(s.size() < k) {
    //             s.insert(dist);
    //             if(s.size() == k) {
    //                 auto it = s.end();
    //                 it--;
    //                 int ele = *it;
    //                 answer.push_back(ele);
    //             }
    //             else answer.push_back(-1);
    //         }
    //         else {
    //             auto it = s.end();
    //             it--;
    //             int ele = *it;
    //             if(ele <= dist) { answer.push_back(ele); continue;}
    //             s.erase(s.find(ele));
    //             s.insert(dist);
    //             it = s.end();
    //             it--;
    //             answer.push_back(*it);
    //         }
    //     }
    //     return answer;
    // }

    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int>answer;
        priority_queue<int>pq;
        for(int i = 0;i < n;i++) {
            int dist = abs(queries[i][0]) + abs(queries[i][1]);
            pq.push(dist);

            if(pq.size() > k) {
                pq.pop();
            }

            if(pq.size() < k) answer.push_back(-1);
            else answer.push_back(pq.top());
        }
        return answer;
    }
};
