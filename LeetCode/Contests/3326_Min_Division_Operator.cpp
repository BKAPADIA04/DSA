class Solution {
public:

    void print(vector<int>nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    } 

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        int i = 1;
        while(i < n) {
            if(i - 2 >= 0 && nums[i-2] > nums[i-1] && answer > 0) { i--; continue;}
            if(nums[i-1] <= nums[i]) i++;
            else {
                int ele = nums[i-1]; int div = 1;
                for(int j = 2; j*j <= ele;j++) {
                    if(ele % j == 0) { div = ele/j; break;}
                }
                if(div == 1) return -1;
                else { nums[i-1] /= div; answer++;}
            }
            // print(nums);
        }
        return answer;
    }
};
