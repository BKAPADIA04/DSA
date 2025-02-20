class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        for(int i = 0;i < 32;i++) {
            if(((1 << i) & left) == 0) continue;

            if((1 << i) <= (right - left)) {
                left = left & (~(1 << i));
            }
        }
        return left;
    }
};
