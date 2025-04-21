#define ll long long
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        ll sum = 0;
        int count = 0;
        for(int i = 0;i < 2 * n;i++) {
            sum += (gas[i % n] - cost[i % n]);
            count++;
            if(sum < 0) {
                sum = 0; count = 0;
            }
            if(count == n) return i - count + 1;
        }
        return -1;
    }
};
