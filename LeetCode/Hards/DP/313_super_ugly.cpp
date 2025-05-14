class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int>answer(n + 1,0);
        answer[0] = 1;

        vector<int>indexes(m,0);
        vector<long long>nextNumber;

        for(int i = 0;i < m;i++) {
            nextNumber.push_back(primes[i]);
        }
        
        for(int i = 1;i < n;i++) {
            long long minimum = LLONG_MAX;
            for(int j = 0;j < m;j++) {
                minimum = min(minimum,nextNumber[j]);
            }
            answer[i] = (int)minimum;

            for(int j = 0;j < m;j++) {
                if(answer[i] == nextNumber[j]) {
                    indexes[j]++;
                    nextNumber[j] = (long long)answer[indexes[j]] * primes[j];
                }
            }
        }
        return answer[n-1];
    }
};
