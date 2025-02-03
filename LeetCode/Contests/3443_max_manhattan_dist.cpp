class Solution {
public:

    int kadane(vector<int>nums,int k) {
        int n = nums.size(); int ans = 0; int sum = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i] == 1) {
                sum += 1;
                ans = max(ans,sum);
            }
            else {
                if(k > 0) {
                    sum += 1; k--;
                    ans = max(ans,sum);
                }
                else {
                    sum -= 1;
                    ans = max(ans,sum);
                }
            }
        }
        return ans;
    }

    int maxDistance(string s, int k) {
        int n = s.size();
        int ans = 0;
        vector<int>north = {1,-1,1,-1};
        vector<int>east = {1,1,-1,-1};
        for(int i = 0;i < 4;i++) {
            vector<int>temp;
            for(int j = 0;j < n;j++) {
                if(s[j] == 'N') {
                    temp.push_back(north[i]);
                }
                if(s[j] == 'S') {
                    temp.push_back(-north[i]);
                }
                if(s[j] == 'E') {
                    temp.push_back(east[i]);
                }
                if(s[j] == 'W') {
                    temp.push_back(-east[i]);
                }
            }
        ans = max(ans,kadane(temp,k));
        }
        return ans;
    }
};
