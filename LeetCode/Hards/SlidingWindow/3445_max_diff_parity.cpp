class Solution {
public:

    int getStatus(int count_a,int count_b) {
        // 0 -> even
        // 1 -> odd

        return ((count_a & 1) << 1) | (count_b & 1);
    }

    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        for(char a = '0';a <= '4';a++) {
            for(char b = '0';b <= '4';b++) {
                if(a == b) continue;
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int count_a = 0; int count_b = 0;
                int prev_a = 0; int prev_b = 0;
                int left = -1;
                int right = 0;

                while(right < n) {
                    count_a += (s[right] == a);
                    count_b += (s[right] == b);
                    while((right - left >= k) && (count_b - prev_b >= 2)) {
                        int leftStatus = getStatus(prev_a,prev_b);
                        best[leftStatus] = min(best[leftStatus],prev_a - prev_b);
                        left++;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int rightStatus = getStatus(count_a,count_b);
                    if(best[rightStatus ^ 0b10] != INT_MAX) {
                        ans = max(ans,count_a - count_b - best[rightStatus ^ 0b10]);
                    }
                    right++;
                }
            }
        }
        return ans;
    }
};
