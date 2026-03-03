class Solution {
public:

    string check(int n) {
        if(n == 1) return "0";

        string tmp = check(n-1);
        int m = tmp.size();
        string ans(m,'0');
        for(int i = 0;i < m;i++) {
            if(tmp[i] == '0') ans[m-1-i] = '1';
            else ans[m-1-i] = '0';
        }

        ans = tmp + "1" + ans;
        return ans;
    }

    char findKthBit(int n, int k) {
        return check(n)[k-1];
    }
};

/*class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};*/
