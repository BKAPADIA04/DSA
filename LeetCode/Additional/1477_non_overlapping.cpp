#define ll long long
class Solution {
public:

    vector<ll>answer(vector<int>&nums, int target) {
        int n = nums.size();
        vector<ll>ans(n,1e9);

        unordered_map<ll,int>preSum;
        preSum[0] = -1;
        ll prefixSum = 0ll;

        for(int i = 0;i < n;i++) {
            prefixSum += nums[i];
            ll rem = prefixSum - (ll)target;
            if(preSum.find(rem) != preSum.end()) {
                ll temp = i - preSum[rem];
                ans[i] = min(ans[i], temp);
            }

            preSum[prefixSum] = i;
        }

        // for(int i = 0;i < n;i++) {
        //     if(ans[i] == 1e9) ans[i] = -1;
        // }
        return ans;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<ll>pre = answer(arr,target);
        vector<int>tempo = arr;
        reverse(tempo.begin(),tempo.end());
        vector<ll>suf = answer(tempo,target);
        reverse(suf.begin(),suf.end());

        // for(auto it : pre) cout << it << " ";
        // cout << endl;
        // for(auto it:suf) cout << it << " ";
        // cout << endl;

        vector<ll>preMin(n),sufMin(n);
        preMin[0] = pre[0];
        for(int i = 1;i < n;i++) {
            preMin[i] = min(preMin[i-1],pre[i]);
        }
        sufMin[0] = suf[0];
        for(int i = 1;i < n;i++) {
            sufMin[i] = min(sufMin[i-1], suf[i]);
        }

        //  for(auto it : preMin) cout << it << " ";
        // cout << endl;
        // for(auto it:sufMin) cout << it << " ";
        // cout << endl;


        ll ans = 1e9;
        for(int i = 0;i < n-1;i++) {
            ll temp = preMin[i];
            if(temp == 1e9) continue;
            if(i + 1 < n) {
                if(suf[i+1] == 1e9) continue;
                temp += suf[i+1];
            }

            ans = min(ans,temp);
        }
        return ans == 1e9 ? -1 : ans;
    }
};
