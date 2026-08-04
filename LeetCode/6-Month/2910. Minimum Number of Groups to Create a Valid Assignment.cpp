class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        int n = balls.size();
        unordered_map<int,int>freq;
        for(int x : balls) freq[x]++;

        int mini = INT_MAX;
        for(auto x : freq) mini = min(mini, x.second);

        int ans = n;
        for(int i = 1;i <= mini;i++) {
            bool flag = true;
            int grps = 0;
            for(auto it : freq) {
                int f = it.second; int num = it.first;
                int g = (f + i) / (i + 1);
                if(g * i > f) {
                    flag = false;
                    break;
                }
                grps += g;
            }
            if(flag) ans = min(ans, grps);
        }

        return ans;
    }
};
