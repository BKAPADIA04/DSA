class Solution {
public:

    static bool comparator(vector<int>&p1,vector<int>&p2) {
        return p1[1] < p2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),comparator);
        int answer = 1;
        int bound = points[0][1];
        for(int i = 1;i < n;i++) {
            if(points[i][0] > bound) {
                answer++;
                bound = points[i][1];
            }
        }
        return answer;
    }
};
