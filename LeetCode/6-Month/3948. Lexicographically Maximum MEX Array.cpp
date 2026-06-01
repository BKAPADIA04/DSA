class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(auto it : nums) freq[it]++;
        int mex = 0;
        while(freq[mex]) mex++;

        vector<int>answer;
        set<int>occ;
        int currMex = 0; int rMex = mex;
        for(int i = 0;i < n;i++) {
            occ.insert(nums[i]);
            while(occ.count(currMex)) currMex++;
            freq[nums[i]]--;

            if(freq[nums[i]] == 0) rMex = min(nums[i], rMex);
            if(currMex == mex) {
                answer.push_back(currMex);
                currMex = 0;
                occ.clear();
                mex = rMex;
            }
        }

        return answer;
    }
};
