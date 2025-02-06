class Solution {
public:

    long long check(vector<int>nums) {
        if(nums.size() == 0) return 0;
        long long gcd_ = nums[0],lcm_ = nums[0];
        for(int i = 1;i < nums.size();i++) {
            gcd_ = gcd(gcd_,nums[i]);
            lcm_ = lcm(lcm_,nums[i]);
        }
        return gcd_ * lcm_;
    }


    long long optimized(vector<int>nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0] * nums[0];
        if(n == 2) return max(nums[0] * nums[0],max(nums[1] * nums[1],(gcd(nums[0],nums[1]) * lcm(nums[0],nums[1]))));
        vector<long long>pre_gcd(n,0);
        vector<long long>pre_lcm(n,0);
        vector<long long>suf_gcd(n,0);
        vector<long long>suf_lcm(n,0);

        pre_gcd[0] = nums[0]; pre_lcm[0] = nums[0]; suf_gcd[n-1] = nums[n-1]; suf_lcm[n-1] = nums[n-1];

        for(int i = 1;i < n;i++) {
            long long temp_gcd = gcd(pre_gcd[i-1],nums[i]);
            pre_gcd[i] = temp_gcd;
            long long temp_lcm = lcm(pre_lcm[i-1],nums[i]);
            pre_lcm[i] = temp_lcm;
        }

        for(int i = n - 2;i >= 0;i--) {
            long long temp_gcd = gcd(suf_gcd[i+1],nums[i]);
            suf_gcd[i] = temp_gcd;
            long long temp_lcm = lcm(suf_lcm[i+1],nums[i]);
            suf_lcm[i] = temp_lcm;
        }

        long long answer = 0;
        for(int i = 1;i < n - 1;i++) {
            long long gcd_ = gcd(pre_gcd[i-1],suf_gcd[i+1]);
            long long lcm_ = lcm(pre_lcm[i-1],suf_lcm[i+1]);

            answer = max(answer,gcd_ * lcm_);
        }
        if(n > 1)
        // first
            answer = max(answer,suf_gcd[1] * suf_lcm[1]);
        
        // last
        answer = max(answer,pre_gcd[n-2] * pre_lcm[n-2]);

        answer = max(answer,pre_gcd[n-1] * pre_lcm[n-1]);

        return answer;
    }

    long long maxScore(vector<int>& nums) {
        // long long ans = 0;
        // for(int i = 0;i < nums.size();i++) {
        //     vector<int>temp;
        //     for(int j = 0;j < nums.size();j++) {
        //         if(i == j) continue;
        //         temp.push_back(nums[j]);
        //     }
        //     ans = max(ans,check(temp));
        // }
        // ans = max(ans,check(nums));
        // return ans;
        return optimized(nums);
    }
};