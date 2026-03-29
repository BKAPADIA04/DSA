class Solution {
public:

    vector<int>factors(int n) {
        vector<int>answer;
        for(int i = 1;i <= sqrt(n);i++) {
            if((n % i) == 0) {
                answer.push_back(i);
                if(i != (n/i)) answer.push_back(n/i);
            }
        }
        return answer;
    }

    bool isSorted(int low, int high, vector<int>&nums) {
        int cnt = 0;
        for(int i = low + 1;i <= high;i++) {
            if(nums[i] < nums[i-1]) cnt++;
        }
        if(nums[low] < nums[high]) cnt++;

        return cnt <= 1;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr = factors(n);
        bool flag = false;
        for(int i = 1;i < n;i++) {
            if(nums[i] < nums[i-1]) flag = true;
        }
        if(!flag) return accumulate(arr.begin(), arr.end(), 0ll);
        long long answer = 0ll;
        for(int it : arr) {
            bool flg = true;
            // cout << endl << it << endl;
            int maxi = nums[0]; int prevMaxi = -1;
            int mini = nums[0]; int prevMini = INT_MAX;
            for(int i = 0; i < n;i++) {
                maxi = max(maxi, nums[i]); 
                mini = min(mini ,nums[i]);
                if(((i + 1) % it) == 0) {
                    if(prevMaxi > mini) {  flg = false; break; }
                    if(!isSorted(i - it + 1, i, nums)) { flg = false; break;}
                    // cout << prevMaxi << " ";
                    prevMaxi = maxi;
                    maxi = 0;
                    mini = INT_MAX;
                }
            }
            // cout << it<< " " << flg << endl;
            if(flg) answer += it;
        }
        return answer;
    }
};
