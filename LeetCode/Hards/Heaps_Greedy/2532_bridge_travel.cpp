class Solution {
public:

    static bool comparator(vector<int>&nums1, vector<int>&nums2) {
        int time1 = nums1[0] + nums1[2];
        int time2 = nums2[0] + nums2[2];

        if(time1 == time2) return nums1[4] < nums2[4];
        return time1 < time2;
    }

    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<int>waitingLeft, waitingRight;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>workingLeft,workingRight;

        for(int i = 0;i < k;i++) time[i].push_back(i);
        sort(time.begin(),time.end(),comparator);

        for(int i = 0;i < time.size();i++) {
            waitingLeft.push(i);
        }

        int currTime = 0;
        
        while(true) {

            while(!workingRight.empty()) {
                int finishTime = workingRight.top()[0];
                int index = workingRight.top()[1];

                if(finishTime > currTime) break;
                waitingRight.push(index);
                workingRight.pop();
            }

            while(!workingLeft.empty()) {
                int finishTime = workingLeft.top()[0];
                int index = workingLeft.top()[1];

                if(finishTime > currTime) break;
                waitingLeft.push(index);
                workingLeft.pop();
            }

            bool checkLeft = n > 0 && !waitingLeft.empty();
            bool checkRight = !waitingRight.empty();

            if(!checkRight && !checkLeft) {
                int nextTime = INT_MAX;
                if(workingLeft.size() > 0) {
                    nextTime = min(nextTime, workingLeft.top()[0]);
                }
                if(workingRight.size() > 0) {
                    nextTime = min(nextTime, workingRight.top()[0]);
                }
                currTime = nextTime;
                continue;
            }

            if(checkRight) {
                int index = waitingRight.top();
                waitingRight.pop();
                currTime += time[index][2];
                if(n == 0 && waitingRight.empty() && workingRight.empty()) return currTime;
                workingLeft.push({currTime + time[index][3], index});
            }
            else {
                int index = waitingLeft.top();
                waitingLeft.pop();
                currTime += time[index][0];
                n--;
                workingRight.push({currTime + time[index][1], index});
            }
        }
        return -1;
    }
};
