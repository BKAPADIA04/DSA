#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0; int count = 0;
        for(int j = 0;j < n;j++) {
            if(nums[j] == 0 || (j == n - 1)) {
                if((j == n - 1) && nums[j] == 1) {
                    count = max(count,j - i + 1);
                }
                else {
                    count = max(count,j - i);
                }
                i = j + 1;
            }
        }
        return count;
    }
};
int main() {}