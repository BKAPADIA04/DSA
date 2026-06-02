class Solution {
public:

    int check(vector<int>&start1, vector<int>&duration1, vector<int>&start2, vector<int>&duration2) {
        int n = start1.size(); int m = start2.size();

        int finish1 = INT_MAX;
        for(int i = 0;i < n;i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for(int i = 0;i < m;i++) {
            finish2 = min(finish2, max(finish1, start2[i]) + duration2[i]);
        }

        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water = check(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = check(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(land_water, water_land);
    }
};
