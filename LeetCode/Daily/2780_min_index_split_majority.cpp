class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return -1;
        unordered_map<int,int>suf;
        for(int i = 0;i < n;i++) {
            suf[nums[i]]++;
        }
        unordered_map<int,int>pre;
        int maj;int count = 0;
        for(int i = 0;i < n;i++) {
            if(count == 0) {
                maj = nums[i];
                count++;
            }
            else {
                if(nums[i] == maj) count++;
                else count--;
            }
            pre[nums[i]]++;
            suf[nums[i]]--;
            int len = (n - i - 1);
            if(count > 0 && (pre[maj] * 2 > i + 1) && (suf[maj] * 2 > len)) return i;
        }
        
        return -1;
    }
};
/* 
Moore Voting
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // Find the majority element
        int x = nums[0], count = 0, xCount = 0, n = nums.size();
        for (auto& num : nums) {
            if (num == x) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                x = num;
                count = 1;
            }
        }

        // Count frequency of majority element
        for (auto& num : nums) {
            if (num == x) {
                xCount++;
            }
        }

        // Check if valid split is possible
        count = 0;
        for (int index = 0; index < n; index++) {
            if (nums[index] == x) {
                count++;
            }
            int remainingCount = xCount - count;
            if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                return index;
            }
        }
        return -1;
    }
};*/
