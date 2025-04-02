class Solution {
public:

    void print(vector<int>v) {
        for(auto it : v) cout << it << " ";
        cout << endl;
    }

    // vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    //     int n = nums1.size(); int m = nums2.size();
    //     vector<vector<int>>answer;
    //     map<int,int>mp;
    //     for(auto it : nums1) {
    //         mp[it[0]]++;
    //         mp[it[1]]--;
    //     }
    //     for(auto it : nums2) {
    //         mp[it[0]]++;
    //         mp[it[1]]--;
    //     }
    //     bool st = false;
    //     int curr = 0;
    //     for(auto it : mp) {
    //         int before = curr;
    //         int posn = it.first; int sweep = it.second;
    //         curr += sweep;
    //         if(curr == before) {
    //             answer.push_back({posn,posn});
    //         }
    //         if(curr == 2) {
    //             st = true;
    //             answer.push_back({posn,0});
    //         }
    //         if(st && curr <= 1) {
    //             st = false;
    //             answer.back()[1] = posn;
    //         }
    //     }
    //     return answer;
    // }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        int i = 0; int j = 0;
        vector<vector<int>>answer;
        while(i < n && j < m) {
            int start = max(nums1[i][0],nums2[j][0]);
            int end = min(nums1[i][1],nums2[j][1]);
            if(start <= end) answer.push_back({start,end});
            if(nums1[i][1] > nums2[j][1]) {
                j++;
            }
            else {
                i++;
            }
        }
        return answer;
    }
};
