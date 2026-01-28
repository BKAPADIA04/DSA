#define ll long long
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ll m, n;
    vector<vector<int>> grid;
    vector<vector<vector<ll>>> dist;

    ll minCost(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        // dist[x][y][tele]
        dist.assign(m, vector<vector<ll>>(n, vector<ll>(k + 1, LLONG_MAX)));

        // Store all cells sorted by value
        vector<pair<int, pair<int,int>>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], {i, j}});

        sort(cells.begin(), cells.end());

        // One pointer per teleport layer
        vector<int> ptr(k + 1, 0);

        using State = tuple<ll, ll, ll, ll>; 
        priority_queue<State, vector<State>, greater<State>> pq;

        for (int i = 0; i <= k; i++)
            dist[0][0][i] = 0;

        pq.push({0, 0, 0, 0}); // cost, tele, x, y

        while (!pq.empty()) {
            auto [cost, tele, x, y] = pq.top();
            pq.pop();

            if (cost > dist[x][y][tele]) continue;
            if (x == m - 1 && y == n - 1) return cost;

            // Normal moves
            if (x + 1 < m) {
                ll nc = cost + grid[x + 1][y];
                if (nc < dist[x + 1][y][tele]) {
                    dist[x + 1][y][tele] = nc;
                    pq.push({nc, tele, x + 1, y});
                }
            }
            if (y + 1 < n) {
                ll nc = cost + grid[x][y + 1];
                if (nc < dist[x][y + 1][tele]) {
                    dist[x][y + 1][tele] = nc;
                    pq.push({nc, tele, x, y + 1});
                }
            }

            // Teleport moves
            if (tele < k) {
                while (ptr[tele] < cells.size() &&
                       cells[ptr[tele]].first <= grid[x][y]) {

                    auto [nx, ny] = cells[ptr[tele]].second;
                    if (cost < dist[nx][ny][tele + 1]) {
                        dist[nx][ny][tele + 1] = cost;
                        pq.push({cost, tele + 1, nx, ny});
                    }
                    ptr[tele]++;
                }
            }
        }

        return -1;
    }
};
