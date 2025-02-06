class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                m[nums[i] * nums[j]]++;
            }
        }

        int answer = 0;
        for(auto it:m) {
            int check = it.second;
            if(check > 1)
                answer += ((check * (check-1))/2) * 8;
        }
        return answer;
    }
};
