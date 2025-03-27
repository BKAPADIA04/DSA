#define ll long long
class Solution {
public:

    vector<int>nextPerm(vector<int>&digits) {
        int n = digits.size();
        int breakPoint = -1;
        for(int i = n - 2; i >= 0;i--) {
            if(digits[i] < digits[i+1]) {
                breakPoint = i; break;
            }
        }
        if(breakPoint == -1) return {};
        for(int i = n - 1; i > breakPoint;i--) {
            if(digits[i] > digits[breakPoint]) {
                swap(digits[i],digits[breakPoint]);
                reverse(digits.begin() + breakPoint + 1,digits.end());
                return digits;
            }
        }
        return digits;
    }


    int nextGreaterElement(int n) {
        vector<int>digits;
        int temp = n;
        while(temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(),digits.end());
        vector<int>ans = nextPerm(digits);
        if(ans.empty()) return -1;
        ll sum = 0ll;
        for(int i = 0;i < ans.size();i++) {
            sum = sum * 10 + ans[i];
            if(sum > INT_MAX) return -1;
        }
        return (int)sum;
    }
};
