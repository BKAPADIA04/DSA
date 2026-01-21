class Solution {
public:

    vector<int>parent;

    int findParent(int x) {
        if(parent[x] != x) return parent[x] = findParent(parent[x]);
        return x;
    }

    void unite(int x,int y) {
        int ultX = findParent(x);
        int ultY = findParent(y);
        if(ultX == ultY) return;

        parent[ultX] = ultY;
    }

    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        parent = vector<int>(threshold + 1,-1);
        for(int i = 0;i <= threshold;i++) parent[i] = i;

        for(int i = 0;i < n;i++) {
            for(int j = nums[i];j <= threshold;j += nums[i]) {
                unite(nums[i],j);
            } 
        }

        set<int>st;
        int ans = 0;

        for(int i = 0;i < n;i++) {
            if(nums[i] > threshold) ans++;
            else st.insert(findParent(nums[i]));
        }
        ans += st.size();
        return ans;
    }
};
