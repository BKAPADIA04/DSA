class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j = 0;
        unordered_map<int,int>freq;
        for(int i = 1;i < n;i++) {
            if(nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
            else {
                freq[nums[i]]++;
            }
        }
        nums.resize(j+1);
        if(k == 0) {
            return freq.size();
        }
        n = nums.size();

        int answer = 0;
        int i = 0; j = 0;
        while(j < n) {
            if(abs(nums[i] - nums[j]) == k) {
                answer++;
                i++;
                j++;
            }
            else if(abs(nums[i] - nums[j]) > k) {
                i++;
            }
            else {
                j++;
            }
        }
        return answer;
    }


    // int findPairs(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     unordered_map<int,int>freq;
    //     for(int i:nums) freq[i]++;
    //     int answer = 0;
    //     if(k == 0) {
    //         for(auto it:freq) {
    //             if(it.second >= 2) answer++;
    //         }
    //     }
    //     else {
    //         for(auto it:freq) {
    //             if(freq.find(it.first + k) != freq.end()) answer++;
    //         }
    //     }
    //     return answer;
    // }
};
