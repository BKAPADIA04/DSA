class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>answer;
        multiset<int>s;
        s.insert(0);

        int n = buildings.size();

        vector<pair<int,int>>nums;
        // sweep line
        for(int i = 0;i < n;i++) {
            nums.push_back({buildings[i][0],-buildings[i][2]});
            nums.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(nums.begin(),nums.end());
        int ongoingHeight = 0;
        for(int i = 0;i < nums.size();i++) {
            int pt = nums[i].first;
            int ht = nums[i].second;

            if(ht < 0) {
                s.insert(-ht);
            }
            else {
                s.erase(s.find(ht));
            }

            if(ongoingHeight != *s.rbegin()) {
                ongoingHeight = *s.rbegin();
                answer.push_back({pt,ongoingHeight});
            }
        }
        return answer;
    }
};
