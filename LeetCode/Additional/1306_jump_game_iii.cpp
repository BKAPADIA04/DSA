class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        queue<int>q;
        vector<int>visited(n,0);
        q.push(start);
        visited[start] = 1;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            if(nums[node] == 0) return true;

            if(node + nums[node] < n && !visited[node + nums[node]]) {
                visited[node + nums[node]] = 1;
                q.push(node + nums[node]);
            }

            if(node - nums[node] >= 0 && !visited[node - nums[node]]) {
                visited[node - nums[node]] = 1;
                q.push(node - nums[node]);
            }
        }
        return false;
    }
};
