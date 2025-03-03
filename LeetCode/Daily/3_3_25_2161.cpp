class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>answer(n);
        int start = 0; int end = n - 1;
        int less = 0; int greater = n - 1;
        while(start < n) {
            if(nums[start] < pivot) {
                answer[less++] = nums[start];
            }
            if(nums[end] > pivot) {
                answer[greater--] = nums[end];
            }
            start++; end--;
        }

        while(less <= greater) answer[less++] = pivot;

        return answer;
    }
};
