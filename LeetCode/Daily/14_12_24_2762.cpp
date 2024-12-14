class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        long long window = 0;
        int i = 0; int j = 0;
        int mini = INT_MAX; int maxi = INT_MIN;
        for(i = 0;i < n;i++) {
            mini = min(nums[i],mini);
            maxi = max(nums[i],maxi);

            if(maxi - mini > 2) {
                window = i-j;
                answer += (window * (window+1))/2;

                j = i;
                mini = nums[i];
                maxi = nums[i];

                while(j > 0 && abs(nums[i] - nums[j-1]) <= 2) {
                    j--;
                    mini = min(nums[j],mini);
                    maxi = max(nums[j],maxi);
                }

                if(j < i) {
                    window = i - j;
                    answer -= (window * (window+1))/2;
                }
            }
        }
        window = i-j;
        answer += (window * (window+1))/2;

        return answer;
    }
};