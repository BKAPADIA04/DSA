class Solution {
public:

    static bool comparator(pair<int,int>&p1,pair<int,int>&p2) {
        return p1.second > p2.second;
    }

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>>v;
        for(int i = 0;i < n;i++) {
            v.push_back({plantTime[i],growTime[i]});
        }
        sort(v.begin(),v.end(),comparator);

        int answer = 0;
        int plantT = 0;

        for(int i = 0;i < n;i++) {
            plantT += v[i].first;
            answer = max(answer, plantT + v[i].second + 1);
        }

        return answer - 1;
    }
};
