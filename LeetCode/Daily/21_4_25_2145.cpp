#define ll long long
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        ll prev = 0ll;
        ll low = 0; ll high = 0;
        for(int i = 0;i < n;i++) {
            ll temp = prev + differences[i];
            low = min(low, temp);
            high = max(high, temp);
            prev = temp;
        }
        ll dif = lower - low;
        ll maxi = high + dif;

        if(maxi > upper || low + dif > maxi || maxi < lower) return 0;

        return upper - maxi + 1;
    }
};
