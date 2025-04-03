class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i < n;i++) {
            mp[nums[i]].push_back(i);
        }

        unordered_set<int>visited;
        visited.insert(0);
        queue<int>q;
        q.push(0);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int j = 0;j < sz;j++) {
                int i = q.front();
                q.pop();

                if(i == (n - 1)) return level;

                if(i + 1 < n && visited.count(i + 1) == 0) {
                    visited.insert(i + 1);
                    q.push(i + 1);
                }

                if(i - 1 >= 0 && visited.count(i - 1) == 0) {
                    visited.insert(i - 1);
                    q.push(i - 1);
                }

                for(auto it : mp[nums[i]]) {
                    if(it == i) continue;
                    if(visited.count(it) == 0) {
                        visited.insert(it);
                        q.push(it);
                    }
                }
                mp[nums[i]].clear();
            }
            level++;
        }
        return -1;
    }
};

