class Solution {
public:
    void print(vector<pair<int,int>>v) {
        for(auto it:v) cout << it.first << " " << it.second << endl;
    }

    static bool comparator(pair<int,int>&p1,pair<int,int>&p2) {
        return p1.second < p2.second;
    }

    bool maxSubstringLength(string s, int k) {
        int n = s.size();
        unordered_map<char,int>firstOcc,lastOcc;
        for(int i = 0;i < n;i++) {
            if(firstOcc.find(s[i]) == firstOcc.end()) firstOcc[s[i]] = i;
            lastOcc[s[i]] = i; 
        }
        vector<pair<int,int>>intervals; 

        for(int i = 0;i < n;i++) {
            if(i != firstOcc[s[i]]) continue;
            int left = i; int right = lastOcc[s[i]];
            bool isValid = true;
            for(int j = left; j <= right;j++) {
                right = max(right,lastOcc[s[j]]);
                if(firstOcc[s[j]] < left) { isValid = false; break;}
            }
            if(right - left + 1 < n && isValid) intervals.push_back({left,right});
        }

        int count = 0; int last = -1;
        sort(intervals.begin(),intervals.end(),comparator);
        for(int i = 0;i < intervals.size();i++) {
            if(intervals[i].first > last)  {
                count++; last = intervals[i].second;
            }
        }

        return count >= k;
    }
};
