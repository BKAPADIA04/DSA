class Solution {
public:

    void check(vector<int>&nums, int x, int time, int &answer, int &k, int count) {
        if(time > answer) return;
        if(count == nums.size()) {
            answer = min(answer, time);
            return;
        }

        for(int i = 0;i < nums.size();i++) {
            if(nums[i] != -1) {
                int temp = nums[i];
                int increment = nums[i]/x + (nums[i] % x > 0 ? 1 : 0);
                nums[i] = -1;
                check(nums,x + k, time + increment, answer, k, count + 1);
                nums[i] = temp;
            }
        }
    }

    int findMinimumTime(vector<int>& nums, int k) {
        int answer = INT_MAX;
        check(nums,1,0,answer,k,0);
        return answer;
    }
};

/*class Solution {
public:
    int ans = 1e9;
    void f(vector<int>& s, int mask, int x, int k, int temp) {
        int n = s.size();
        if(mask == (1<<n)-1) {
            ans = min(ans, temp);
            return;
        }
        int sum = x, add = 0;
        for(int i=0; i<n; i++) {
            if(mask & (1<<i)) continue;
            add = (s[i] + x - 1)/x;
            f(s, mask | (1<<i), x + k, k, temp + add);
        }
    }
    int findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(), strength.end());
        f(strength, 0, 1, K, 0);
        return ans;
    }
};*/
