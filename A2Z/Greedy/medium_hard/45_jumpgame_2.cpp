class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0; int last = 0;
        int answer = 0;
        for(int i = 0;i < n - 1;i++) {
            maxi = max(maxi,i + nums[i]);
            if(last == i) {
                answer++;
                last = maxi;
            }
        }
        return answer;
    }
};
