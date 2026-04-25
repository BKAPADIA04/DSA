class Solution {
public:
    vector<long long> nums;

    bool check(long long dist, int side, int k) {
        long long perimeter = 4LL * side;

        for (long long start : nums) {
            long long curr = start;
            long long lastAllowed = start + perimeter - dist;
            int chosen = 1;

            while (chosen < k) {
                auto it = lower_bound(nums.begin(), nums.end(), curr + dist);

                if (it == nums.end() || *it > lastAllowed)
                    break;

                curr = *it;
                chosen++;
            }

            if (chosen == k) return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        nums.clear();

        for (auto it : points) {
            long long x = it[0], y = it[1];

            if (y == 0) {
                nums.push_back(x);                     // bottom
            }
            else if (x == side) {
                nums.push_back(side + y);              // right
            }
            else if (y == side) {
                nums.push_back(3LL * side - x);        // top
            }
            else {
                nums.push_back(4LL * side - y);        // left
            }
        }

        sort(nums.begin(), nums.end());

        long long low = 1, high = 4LL * side, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, side, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};
