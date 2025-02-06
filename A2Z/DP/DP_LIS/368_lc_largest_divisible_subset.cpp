class Solution {
public:

    void print(vector<int>dp) {
        for(auto it:dp) cout << it << " ";
        cout << endl;
    }

    void check(vector<int>&nums,vector<int>&dp,int index,int prev_index,vector<int>&answer,vector<int>&temp) {
        if(index == nums.size()) {
            if(answer.size() < temp.size()) {
                answer = temp;
            }
            // print(answer);
            return;
        }

        // if(dp[index][prev_index+1] != -1) return;
        // not taken
        check(nums,dp,index+1,prev_index,answer,temp);

        // taken
        // int i;
        // for(i = 0;i < temp.size();i++) {
        //     if(nums[index] % temp[i] != 0 && temp[i] % nums[index] != 0 ) break;
        // }
        if((temp.size() == 0 || nums[index] % temp.back() == 0)  && dp[index] < temp.size()+1) {
            cout << "hi" << endl;
            dp[index] = temp.size()+1;
            temp.push_back(nums[index]);
            check(nums,dp,index+1,index,answer,temp);
            temp.pop_back();
        }
        // dp[index][prev_index+1] = answer.size();
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int>dp(n,-1);
        // vector<int>answer = {},temp = {};
        // check(nums,dp,0,-1,answer,temp);
        // return answer;


        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);

        for(int i = 0;i < n;i++) {
            hash[i] = i;
            for(int j = 0;j < i;j++) {
                if(nums[i] % nums[j] == 0 && (1 + dp[j] > dp[i])) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }

        int ans = -1;
        int last_index =-1;
    
        for(int i=0; i<=n-1; i++) {
            if(dp[i]> ans) {
                ans = dp[i];
                last_index = i;
            }
        }

        vector<int>answer;
        answer.push_back(nums[last_index]);

        while(hash[last_index] != last_index) {
            last_index = hash[last_index];
            answer.push_back(nums[last_index]);
        }
        reverse(answer.begin(),answer.end());

        return answer;
    }
};
