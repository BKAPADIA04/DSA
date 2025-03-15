class Solution {
public:

    bool check(vector<int>&nums,int mid, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i] <= mid) {
                count++;
                i++;
                if(count >= k) return true;
            }
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());

        int answer = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            if(check(nums,mid,k)) {
                answer = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return answer;
    }
};
