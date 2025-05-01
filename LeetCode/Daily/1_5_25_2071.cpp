class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int n = tasks.size(); int m = workers.size();
        deque<int>dq;
        int taskIndex = 0;
        for(int i = m - mid;i < m;i++) {
            while(taskIndex < mid && tasks[taskIndex] <= workers[i] + strength) {
                dq.push_back(tasks[taskIndex++]);
            }

            if(dq.empty()) return false;

            if(workers[i] >= dq.front()) {
                dq.pop_front();
            }
            else if(pills > 0) {
                pills--;
                dq.pop_back();
            }
            else return false;
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(); int m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0; int high = min(n,m);
        int answer = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(tasks,workers,pills,strength,mid)) {
                answer = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
