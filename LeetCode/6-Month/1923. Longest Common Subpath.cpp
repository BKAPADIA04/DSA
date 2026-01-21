class Solution {
private:
    static const long long MOD1 = 1000000007LL;
    static const long long MOD2 = 1000000009LL;
    static const long long BASE1 = 91138233LL;
    static const long long BASE2 = 97266353LL;

    vector<long long> pref1, pref2;
    vector<long long> pow1, pow2;
    vector<vector<int>> paths;

    unordered_map<long long, int> hashCount;
    unordered_map<long long, int> lastPathIdx;

public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        this->paths = paths;

        int minLen = INT_MAX, maxLen = 0;
        for (auto& p : paths) {
            minLen = min(minLen, (int)p.size());
            maxLen = max(maxLen, (int)p.size());
        }

        pref1.resize(maxLen + 1);
        pref2.resize(maxLen + 1);
        pow1.resize(maxLen + 1);
        pow2.resize(maxLen + 1);

        int lo = 0, hi = minLen, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    bool feasible(int len) {
        if (len == 0) return true;

        hashCount.clear();
        lastPathIdx.clear();

        for (int pathIdx = 0; pathIdx < paths.size(); pathIdx++) {
            auto& path = paths[pathIdx];
            int sz = path.size();

            pref1[0] = pref2[0] = 0;
            pow1[0] = pow2[0] = 1;

            for (int i = 1; i <= sz; i++) {
                pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
                pow2[i] = (pow2[i - 1] * BASE2) % MOD2;

                pref1[i] = (pref1[i - 1] * BASE1 + path[i - 1]) % MOD1;
                pref2[i] = (pref2[i - 1] * BASE2 + path[i - 1]) % MOD2;
            }

            for (int end = len; end <= sz; end++) {
                int start = end - len + 1;

                long long h1 =
                    (pref1[end]
                    - pref1[start - 1] * pow1[len] % MOD1 + MOD1) % MOD1;

                long long h2 =
                    (pref2[end]
                    - pref2[start - 1] * pow2[len] % MOD2 + MOD2) % MOD2;

                // combine two hashes into one 64-bit key
                long long combined = (h1 << 32) ^ h2;

                if (!lastPathIdx.count(combined) || lastPathIdx[combined] != pathIdx) {
                    lastPathIdx[combined] = pathIdx;
                    hashCount[combined]++;
                }
            }
        }

        for (auto& [_, cnt] : hashCount) {
            if (cnt == (int)paths.size())
                return true;
        }
        return false;
    }
};
