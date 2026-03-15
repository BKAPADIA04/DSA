class Solution {
public:

    vector<int> parent, sz;
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 != r2) {
            if (sz[r1] < sz[r2]) {
                parent[r1] = r2;
                sz[r2] += sz[r1];
            }
            else {
                parent[r2] = r1;
                sz[r1] += sz[r2];
            }
        }
    }

    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n); sz.assign(n, 1);
        for(int i = 0;i < n;i++) {
            parent[i] = i;
        }

        unordered_map<int, int> xmap, ymap;
        for (int i = 0; i < n; i++) {
            if (xmap.count(points[i][0])) unite(i, xmap[points[i][0]]);
            else xmap[points[i][0]] = i;
            if (ymap.count(points[i][1])) unite(i, ymap[points[i][1]]);
            else ymap[points[i][1]] = i;
        }

        int m1 = 0, m2 = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                if (sz[i] > m1) { m2 = m1; m1 = sz[i]; }
                else if (sz[i] > m2) { m2 = sz[i]; }
            }
        }
        return m1 + m2 + 1;

    }
};

/*class Solution {
public:

    map<pair<int,int>, pair<int,int>>mp;
    map<pair<int,int>, int>sz;

    pair<int,int>findParent(pair<int,int>p) {
        auto it = mp.find(p);
        if(it == mp.end()) return mp[p] = findParent(mp[p]);
        auto it1 = mp[p];
        int xP = it1.first; int yP = it1.second;

        if(xP == p.first && yP == p.second) return {xP,yP};

        return mp[p] = findParent(mp[p]);
    }

    void unite(pair<int,int>p1, pair<int,int>p2) {
        auto ult1 = findParent(p1);
        auto ult2 = findParent(p2);

        if(ult1.first == ult2.first && ult1.second == ult2.second) return;

        int sz1 = sz[ult1]; int sz2 = sz[ult2];
        if(sz1 > sz2) {
            sz[ult1] += sz[ult2];
            mp[ult2] = ult1;
        }
        else {
            sz[ult2] += sz[ult1];
            mp[ult1] = ult2;
        }
    }

    static bool comparator(pair<int,int>p1, pair<int,int>p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
    static bool comparator2(pair<int,int>p1, pair<int,int>p2) {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    }
    
    int maxActivated(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<pair<int,int>>nums;
        
        for(auto it : points) {
            int x = it[0]; int y = it[1];
            sz[{x,y}] = 1;
            mp[{x,y}] = {x,y};
            nums.push_back({x,y});
        }

        sort(nums.begin(), nums.end(), comparator);

        for(int i = 1;i < m;i++) {
            if(nums[i].first == nums[i-1].first) unite(nums[i], nums[i-1]);
        }
        sort(nums.begin(), nums.end(), comparator2);

        for(int i = 1;i < m;i++) {
            if(nums[i].second == nums[i-1].second) unite(nums[i], nums[i-1]);
        }

        int maxi = 0; int smaxi = 0;

        for(auto it : mp) {
            if(it.first.first == it.second.first && it.first.second == it.second.second) {
                int size = sz[{it.first.first, it.first.second}];
                if(size > maxi) {
                    smaxi = maxi;
                    maxi = size;
                }
                else if(size > smaxi) {
                    smaxi = size;
                }
            }
        }
        
        return maxi + smaxi + 1;
    }
};*/
