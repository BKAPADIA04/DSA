class Solution {
public:

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries,int k) {
        vector<int>sweep(nums.size()+1);
        for(int i = 0;i <= k;i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            sweep[l] += val;
            sweep[r+1] -= val;
        }

        int sum = 0;

        for(int i = 0;i < nums.size();i++) {
            // if(nums[i] == 0) continue;
            sum += sweep[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum == 0) return 0;
        int l = 0; int r = n - 1;
        int answer = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isZeroArray(nums,queries,mid)) {
                answer = mid+1; r = mid - 1;
            }
            else {
                l = mid + 1;
            }
            cout << answer << endl;
        }
        return answer;
    }
};
















