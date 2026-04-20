class Solution {
public:
    bool dfs(int r0, int r1, int r2, int r, bool isAlice) {
    if (r == 0 || r0 < 0 || r1 < 0 || r2 < 0)
        return true;
    if (r0 == 0 && r1 == 0 && r2 == 0)
        return !isAlice;
    return !dfs(r0 - 1, r1, r2, r % 3, !isAlice) 
        || !dfs(r0, r1 - 1, r2, (r + 1) % 3, !isAlice) 
        || !dfs(r0, r1, r2 - 1, (r + 2) % 3, !isAlice);
}
bool stoneGameIX(vector<int>& stones) {
    int r[3] = {};
    for (auto s : stones)
        ++r[s % 3];
    return dfs(r[0] % 2, r[1], r[2], 3, true);
}
};
