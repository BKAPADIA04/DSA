class Solution {
public:

    static bool comparator(vector<int>&a, vector<int>&b) {
        return a[1] < b[1];
    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(),tasks.end(),comparator);
        for(auto it : tasks) cout << it[0] << " " << it[1] << " " << it[2] << endl;
        vector<int>v(2002,0);
        
        for(int i = 0;i < n;i++) {
            int start = tasks[i][0]; int end = tasks[i][1]; int duration = tasks[i][2];
            for(int j = end;j >= start;j--) {
                if(duration == 0) break;
                if(v[j]) duration--;
            }
            
            for(int j = end;j >= start;j--) {
                if(duration == 0) break;
                if(v[j]) continue;
                v[j] = 1; 
                duration--;
            }
        }
        
        return accumulate(v.begin(),v.end(),0);
    }
};

/*int findMinimumTime(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
    int res = 0, j = 0, mx = 0;
    for (vector<int>& t : tasks) mx = max(mx, t[1]);
    for (int i = 1; i <= mx; i++) {
        while (j < tasks.size() && tasks[j][0] == i)
            pq.push({tasks[j][1] - tasks[j][2] - res + 1, tasks[j++][1]});
        while (pq.size() && pq.top().second < i) pq.pop();
        if (pq.size() && pq.top().first + res == i) res++;
    }
    return res;
}*/
