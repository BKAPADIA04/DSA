#define ll long long
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long c[2] = {0, 0};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                c[s[i] - '0']++;
            }
        }
        long long c0 = c[0], c1 = c[1];

        long long res1 = (c0 + c1) * (long long)flipCost;
        long long res2 = min(c0, c1) * swapCost + abs(c0 - c1) * (long long)flipCost;
        long long res3 = min(c0, c1) * swapCost + (abs(c0 - c1) / 2) * ((long long)swapCost + crossCost) + (abs(c0 - c1) % 2) * (long long)flipCost;

        return min({res1, res2, res3});
    }
};
