class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int,int>>nums;
        unordered_map<int,int>healthMap;
        unordered_map<int,char>dirMap;

        for(int i = 0;i < n;i++) {
            nums.push_back({positions[i], i});
            healthMap[i] = healths[i];
            dirMap[i] = directions[i];
        }

        sort(nums.begin(), nums.end());

        stack<pair<int,int>>st; // i, dir
        for(int i = 0;i < n;i++) {
            int robotNo = nums[i].second;
            if(dirMap[robotNo] == 'L') {
                bool flag = true;
                if(st.empty()) { st.push({robotNo, -1}); continue;}
                while(!st.empty()) {
                    int dir = st.top().second;
                    int index = st.top().first;
                    if(dir == -1) {
                        // st.push({robotNo, -1});
                        flag = false;
                        break;
                    }
                    else {
                        if(healthMap[robotNo] >= healthMap[index]) {
                            st.pop();
                            if(healthMap[robotNo] == healthMap[index]) { break;}
                            if(st.size() == 0) flag = false;
                            healthMap[robotNo]--;
                        }
                        else {
                            healthMap[index]--;
                            break;
                        }
                    }
                }
                
                if(!flag) st.push({robotNo, -1});
            }
            else {
                st.push({robotNo, 1});
            }
        }

        vector<pair<int,int>>temp;
        while(!st.empty()) {
            int idx = st.top().first;
            temp.push_back({idx, healthMap[idx]});
            st.pop();
        }

        sort(temp.begin(), temp.end());
        vector<int>answer;
        for(auto it:temp) answer.push_back(it.second);
        return answer;
    }
};
