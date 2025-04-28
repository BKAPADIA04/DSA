class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long answer = 0ll;
        vector<long long>prefix(n+1);
        for(int i = 1;i <= n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1] * 1ll;
        }
        int i;int j = 0;
        // for(i = 0;i < n;i++) {
        //     long long check = (prefix[i+1] - prefix[j]) * (i-j+1) * 1ll;
            
        //     if(check >= k) {
        //         long long window = i - j;
        //         answer += 1ll * (window * (window + 1))/2;

                
        //         j = i;
        //         // TLE as k is very large
        //         while(j > 0 && ((prefix[i+1] - prefix[j]) * (i-j+1) * 1ll) < k) {
        //             j--;
        //         }
        //         j += 1;
        //         if(j < i) {
        //             window = i-j;
        //             answer -= 1ll * (window * (window + 1))/2;
        //         }
        //     }
        // }
        // long long window = i - j;
        // answer += 1ll * (window * (window + 1))/2;

        O(nlogn)
        for(i = 1; i <= n;i++) {
            int low = i;
            int high = n;
            int res = -1;

            while(low <= high) {
                int mid = (low + high)/2;
                if((prefix[mid] - prefix[i-1]) * (mid - i + 1) < k) {
                    res = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            if(res == -1) continue;

            answer += (res-i+1);
        }
        return answer;
    }
};

O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0;
        long long score = 0;
        int l=0,r=0;
        long long ans = 0;

        while(r<n){
            sum += nums[r];
            score = sum * (r-l+1);

            while(l<r && score >= k){
                sum -= nums[l];
                l++;
                score = sum * (r-l+1);
            }

            if(score < k){
                ans += r-l+1;
            }
            r++;
        }

        return ans;
    }
};






















