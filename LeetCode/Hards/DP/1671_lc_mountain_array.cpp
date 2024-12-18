class Solution {
public:

    void print(vector<int>nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    }

    vector<int>lis(vector<int>&nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return dp;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>pre = lis(nums);
        print(pre);
        vector<int>temp = nums;
        reverse(temp.begin(),temp.end());
        vector<int>suf = lis(temp);
        reverse(suf.begin(),suf.end());
        print(suf);

        int answer = INT_MAX;
        for(int i = 0; i < nums.size();i++) {
            if(i == 0 || (i == nums.size()-1)) continue;
            if(pre[i] == 1 || suf[i] == 1) continue;
            int check = (i+1 - pre[i]) + (nums.size()-i-suf[i]);
            answer = min(answer,check);
        }
        return answer;
    }
};

// better using binary search
/*class Solution {
public:
    vector<int> getLongestIncreasingSubsequenceLength(vector<int>& v) {
        vector<int> lisLen(v.size(), 1);
        vector<int> lis = {v[0]};

        for (int i = 1; i < v.size(); i++) {
            // Index of the first element which is equal to or greater than
            // v[i].
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

            // Add to the list if v[i] is greater than the last element.
            if (index == lis.size()) {
                lis.push_back(v[i]);
            } else {
                // Assign the value v[i] to the returned index as it's going to
                // smaller than or equal to the existing element.
                lis[index] = v[i];
            }

            lisLen[i] = lis.size();
        }

        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lisLength = getLongestIncreasingSubsequenceLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> ldsLength = getLongestIncreasingSubsequenceLength(nums);
        // Reverse the length array to correctly depict the lenght of longest
        // decreasing subsequence for each index.
        reverse(ldsLength.begin(), ldsLength.end());

        int minRemovals = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals =
                    min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
            }
        }

        return minRemovals;
    }
};*/