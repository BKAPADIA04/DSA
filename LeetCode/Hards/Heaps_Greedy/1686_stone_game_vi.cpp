class Solution {
public:

    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        int aliceScore = 0;
        int bobScore = 0;

        vector<pair<int,int>>nums;
        for(int i = 0;i < n;i++) {
            nums.push_back({aliceValues[i] + bobValues[i], i});
        }

        sort(nums.begin(),nums.end(),greater<pair<int,int>>());
        int chance = 1;
        for(int i = 0;i < n;i++) {
            if(chance) aliceScore += aliceValues[nums[i].second];
            else bobScore += bobValues[nums[i].second];

            chance = 1 - chance;
        }

        if(aliceScore > bobScore) return 1;
        if(bobScore > aliceScore) return -1;
        return 0;
    }
};
