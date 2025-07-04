class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int answer = 0;
        int logFloor;
        while(k != 1) {
            logFloor = log2(k);
            if(((long long)1 << logFloor) == k) logFloor--;
            k = k - ((long long)1 << logFloor);
            if(operations[logFloor]) answer++;
        }
        return 'a' + (answer % 26);
    }
};
