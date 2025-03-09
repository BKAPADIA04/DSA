#define ll long long
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<ll>>nums;
        for(ll i = 0;i < nums1.size();i++) {
            nums.push_back({nums1[i],nums2[i],i});
        }

        sort(nums.begin(),nums.end());
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        vector<ll>answer(nums1.size(),0);

        ll sum = 0;
        for(ll i = 0;i < nums.size();i++) {
            int a = nums[i][0];
            int b = nums[i][1];
            int index = nums[i][2];

            if(i > 0 && nums[i-1][0] == nums[i][0]) {
                answer[index] = answer[nums[i-1][2]];
            }
            else answer[index] = sum;
            pq.push(b);
            sum += b;

            while(pq.size() > k) {
                ll number = pq.top();
                pq.pop();
                sum = sum - number;
            }
        }
        return answer;
    }
};
