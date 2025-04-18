class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double>answer(n,-1.0);
        stack<int>st;
        for(int i = n - 1;i >= 0;i--) {
            while(!st.empty()) {
                int top = st.top();
                if(cars[i][1] > cars[top][1]) {
                    double collisionTime = (double)(cars[top][0] - cars[i][0]) / ((cars[i][1] - cars[top][1]) * 1.0);
                    if(answer[top] == -1 || collisionTime <= answer[top]) {
                        answer[i] = collisionTime; break;
                    }
                }
                st.pop();
            }
            st.push(i);
        }

        return answer;
    }
};
