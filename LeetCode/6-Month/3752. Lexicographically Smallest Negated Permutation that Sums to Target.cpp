#define ll long long
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll sum = (ll)((ll)n * (ll)(n + 1)) / 2;
    
        if(target > sum || target < -sum || (abs(sum - target) % 2) == 1) return {};

        vector<int>answer;

        ll index = n - 1;
        while(index >= 0) {
            ll check = 1ll * (index + 1);

            if((sum - 2ll * check) >= target) { 
                answer.push_back(-(index + 1));
                sum = sum - 2ll * check;
            }
            else {
                answer.push_back((index + 1));
            }
            index--;
        }

        sort(answer.begin(),answer.end());
        return answer;
    }
};
