class Solution {

    vector<int>segmentTree;
    void constructTree(vector<int>&baskets,int start,int end,int node) {
        if(start == end) {
            segmentTree[node] = baskets[start];
            return;
        }

        int mid = (start + end)/2;
        constructTree(baskets,start,mid,2*node);
        constructTree(baskets,mid+1,end,2*node+1);
        segmentTree[node] = max(segmentTree[2*node],segmentTree[2*node+1]);
    }

    int search(int node,int start,int end,int k) {
        if(segmentTree[node] < k) return -1;
        if(start == end) {
            segmentTree[node] = -1;
            return start;
        }
        int mid = (start + end)/2;
        int pos = segmentTree[2*node] >= k ? search(2*node,start,mid,k) : search(2*node+1,mid+1,end,k);
        segmentTree[node] = max(segmentTree[2*node],segmentTree[2*node+1]);
        return pos;
    }


public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segmentTree.assign(4*n,0);
        int ans = 0;
        constructTree(baskets,0,n-1,1);
        for(int i = 0;i < n;i++) {
            if(search(1,0,n-1,fruits[i]) == -1) {
                ans++;
            }
        }
        return ans;
    }
};
