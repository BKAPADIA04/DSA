class Solution {
public:
    void print(vector<int>&nums) {
        for(auto it : nums) {
            cout << it << " ";
        }
        cout << endl;
    }

    int LIS_Optimized(vector<int>&arr) {
        int n = arr.size();
        vector<int>lis;
        // lis.push_back(arr[0]);
        for(int i = 0;i < n;i++) {
            auto it = upper_bound(lis.begin(), lis.end(), arr[i]);
            if (it == lis.end())
                lis.push_back(arr[i]); 
            else
                *it = arr[i];
        }
        cout << arr.size() - lis.size() << endl;
        return arr.size() - lis.size();
    }

    int kIncreasing(vector<int>& nums, int k) {
        int count = 0;
        
        for(int i = 0;i < k;i++) {
            vector<int>subseq;
            for(int j = i;j < nums.size();j += k) {
                subseq.push_back(nums[j]);
            }
            count += LIS_Optimized(subseq);
        }
        return count;
    }
    
};