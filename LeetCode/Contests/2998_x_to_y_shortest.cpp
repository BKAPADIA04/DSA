class Solution {
public:

    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>>q;
        q.push({0,x});
        set<int>s;
        s.insert(x);
        while(!q.empty()) {
            int val = q.front().second;
            int step = q.front().first;
            q.pop();
            if(val == y) return step;
            if(val % 11 == 0) {
                if(s.find(val/11) == s.end()) {
                    s.insert(val/11);
                    q.push({step + 1,val/11});
                }
            }
            if(val % 5 == 0) {
                if(s.find(val/5) == s.end()) {
                    s.insert(val/5);
                    q.push({step + 1,val/5});
                }
            }
            if(s.find(val + 1) == s.end()) {
                s.insert(val + 1);
                q.push({step + 1,val + 1});
            }
            if(val - 1 > 0 && s.find(val - 1) == s.end()) {
                s.insert(val - 1);
                q.push({step + 1, val - 1});
            }
        }
        return -1;
    }
};
