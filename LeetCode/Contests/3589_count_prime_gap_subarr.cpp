#define ll long long
class Solution {
public:

    vector<int>primes;

    void sieveEra() {
        primes[0] = primes[1] = 0;
        for(int i = 2;i * i < primes.size();i++) {
            if(!primes[i]) continue;
            for(int j = i * i;j < primes.size();j += i) {
                primes[j] = 0;
            }
        }
    }

    int check(vector<int>&nums,int k) {
        int n = nums.size();
        multiset<int>ms;
        int ans = 0; int left = 0; int right = 0;
        int firstLastPrime = -1; int secondLastPrime = -1; // right
        while(right < n) {
            if(primes[nums[right]]) {
                ms.insert(nums[right]);
                secondLastPrime = firstLastPrime;
                firstLastPrime = right;
            }

            while(ms.size() > 1 && (*ms.rbegin() - *ms.begin() > k)) {
                if(primes[nums[left]]) {
                    ms.erase(ms.find(nums[left]));
                }
                left++;
            }

            if(ms.size() >= 2) ans = ans + (secondLastPrime - left + 1);
            right++;
        }
        return ans;   
    }
    
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        primes = vector<int>(50005,1);
        sieveEra();
        return check(nums,k);
    }
};

/*class Solution {
    const int MAX_NUM = 50000;
public:
    int primeSubarray(vector<int>& nums, int k) {
        // 1. Get all prime with Sieve of Eratosthenes
        bool prime[MAX_NUM+1];
        fill(prime, prime+MAX_NUM+1, true);
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=MAX_NUM; ++i){
            if(prime[i]){
                for(int j=i*i; j <= MAX_NUM; j+=i){
                    prime[j] = false;
                }
            }
        }
        int n = nums.size();
        int count = 0;
        // 2. Sliding window with monotonic queue to maintain max min value.
        int left = 0; 
        // All deque record index
        deque<int> primePos;
        deque<int> monoMax, monoMin;
        for(int right = 0; right < n; ++right){ // [left, right]
            // Put right into queue when it is prime
            if(prime[ nums[right] ] == true){
                primePos.push_back(right);
                while(!monoMax.empty() && nums[right] >= nums[monoMax.back()]){
                    monoMax.pop_back();
                }
                monoMax.push_back(right);
                while(!monoMin.empty() && nums[right] <= nums[monoMin.back()]){
                    monoMin.pop_back();
                }
                monoMin.push_back(right);
                // move the window left to make the window's prime diff is always <= k
                // at least one number == right and always smaller than k
                while(nums[monoMax.front()] - nums[monoMin.front()] > k){
                    left = primePos.front() + 1;
                    primePos.pop_front();
                    while(monoMax.front() < left){
                        monoMax.pop_front();
                    }
                    while(monoMin.front() < left){
                        monoMin.pop_front();
                    }
                }
            }
            // update result when valid
            if(primePos.size() >= 2){
                // from left to primePos[]
                int len = primePos.size();
                count += primePos[len-2] - left + 1;
            }
        }
        return count;
    }
};*/
