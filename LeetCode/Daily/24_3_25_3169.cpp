class Solution {
public:
    void print(vector<vector<int>>v) {
        for(auto it:v) {
            for(auto it1:it) cout << it1 << " ";
            cout << endl;
        }
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>nums; int ans = 0;
        for(int i = 0;i < meetings.size();i++) {
            if(nums.size() == 0 || nums.back()[1] < meetings[i][0]) {
                nums.push_back(meetings[i]);
            }
            else {
                nums.back()[1] = max(nums.back()[1],meetings[i][1]);
            }
        }
        for(int i = 0;i < nums.size();i++) {
            ans += nums[i][1] - nums[i][0] + 1;
        }
        return days - ans;
    }
};
