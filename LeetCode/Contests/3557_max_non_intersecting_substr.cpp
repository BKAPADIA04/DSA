class Solution {
public:

    void print(vector<pair<int,int>>v) {
        for(auto it:v) {
            cout << it.first << " " << it.second << endl;
        }
    }

    static bool comparator(pair<int,int>&p1,pair<int,int>&p2) {
        return p1.second < p2.second;
    }
    
    int maxSubstrings(string word) {
        int n = word.size();
        vector<pair<int,int>>nums;
        vector<vector<int>>freq(26);
        for(int i = 0;i < n;i++) {
            char ch = word[i];
            freq[ch-'a'].push_back(i);
        }
        for(int i = 0;i < 26;i++) {
            vector<int>temp = freq[i];
            for(int j = 1;j < temp.size();j++) {
                if(j - 1 >= 0 && abs(temp[j] - temp[j-1]) >= 3) {
                    nums.push_back({temp[j-1],temp[j]});
                }
                if(j - 2 >= 0 && abs(temp[j] - temp[j-2]) >= 3) {
                    nums.push_back({temp[j-2],temp[j]});
                }
                if(j - 3 >= 0 && abs(temp[j] - temp[j-3]) >= 3) {
                    nums.push_back({temp[j-3],temp[j]});
                }
            }
        }

        sort(nums.begin(),nums.end(),comparator);
        
        // print(nums);
        if(nums.size() == 0) return 0;
        
        int ans = 1;
        int bound = nums[0].second;
        for(int i = 1;i < nums.size();i++) {
            if(nums[i].first > bound) {
                ans++;
                bound = nums[i].second;
            }
        }
        
        return ans;
    }
};
