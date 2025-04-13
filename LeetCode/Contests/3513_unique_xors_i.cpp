class Solution {
public:

    bool isPowerOfTwo(int n) {
        if(n > 0 && ((n & (n-1)) == 0)) return true;
        return false;
    }

    int logbase2(int n) {
        return (log(n)/log(2));
    }
    
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int logg = logbase2(n);

        // if(isPowerOfTwo(n)) {
        //     return (int)pow(2,logg + 1) - 1;
        // }

        return (int)pow(2,logg + 1);
    }
};
