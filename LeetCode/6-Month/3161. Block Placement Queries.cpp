class Solution {
public:

    int MX = 50000;
    vector<int> seg;
    set<int> obstacles;

    void update(int pos, int node, int val, int low, int high) {
        if(low == high) {
            seg[node] = val;
            return;
        }

        int mid = (low + high)/2;
        if(pos <= mid) {
            update(pos, 2*node, val, low, mid);
        }
        else {
            update(pos, 2*node+1, val, mid+1, high);
        }

        seg[node] = max(seg[2*node], seg[2*node + 1]);
    }

    int queryMax(int ql, int qr, int node, int low, int high) {
        if(ql <= low && high <= qr) return seg[node];

        int mid = (low + high)/2;

        int ans = 0;

        if(ql <= mid) {
            ans = max(ans, queryMax(ql, qr, 2*node, low, mid));
        }

        if(qr > mid) {
            ans = max(ans, queryMax(ql, qr, 2*node+1, mid+1, high));
        }

        return ans;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        seg.assign(4 * (MX + 1), 0);

        obstacles.insert(0);
        obstacles.insert(MX);

        update(MX, 1, MX, 0, MX);

        vector<bool> result;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto rightIt = obstacles.upper_bound(x);
                int right = *rightIt;
                int left = *prev(rightIt);

                obstacles.insert(x);

                update(x, 1, x - left, 0, MX);
                update(right, 1, right - x, 0, MX);
            } 
            else {
                int x = q[1];
                int size = q[2];

                auto it = obstacles.upper_bound(x);
                int leftObstacle = *prev(it);

                int bestGap = queryMax(0, leftObstacle, 1, 0, MX);

                // Last partial segment from leftObstacle to x
                bestGap = max(bestGap, x - leftObstacle);

                result.push_back(bestGap >= size);
            }
        }

        return result;
    }
};
