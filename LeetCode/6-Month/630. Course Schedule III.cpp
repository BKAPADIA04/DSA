class Solution {
public:

    static bool comparator(vector<int>&a, vector<int>&b) {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), comparator);

        int endTime = 0; int ans = 0;
        priority_queue<int>pq;
        for(int i = 0;i < n;i++) {
            pq.push(courses[i][0]);
            endTime += courses[i][0];

            if(endTime > courses[i][1]) {
                endTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
