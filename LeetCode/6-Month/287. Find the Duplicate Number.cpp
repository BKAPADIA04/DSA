class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;

        int ans = 0;

        while(low <= high) {    
            int mid = (low + high)/2;
            int count = 0;
            for(int num : nums) {
                if(num <= mid) count++;
            }

            if(count > mid) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow = 0, fast = 0;
       
       // Phase 1: Detect cycle (meeting point)
       while(true){
           slow = nums[slow];
           fast = nums[nums[fast]];
           if(slow == fast){
               break;
           }
       }
       
       // Phase 2: Find cycle entrance (duplicate number)
       slow = 0;
       while(slow != fast){
           slow = nums[slow];
           fast = nums[fast];
       }
       
       return slow;
    }
};*/
