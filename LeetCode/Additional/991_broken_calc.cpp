class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int temp = target;
        int ans = 0;
        while(temp > startValue) {
            if(temp & 1) temp++;
            else temp /= 2;
            ans++;
        }
        ans = ans + (startValue - temp);
        return ans;
    }
};
