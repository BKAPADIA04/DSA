class Solution {
public:
    void print(vector<int>nums) {
        for(auto it:nums) {
            cout << it << " ";
        }
        cout << endl;
    }
    long long findScore(vector<int>& nums) {
        vector<pair<long long,long long>>v;
        vector<int>marked(nums.size(),0);
        for(int i = 0;i < nums.size();i++) {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        long long answer = 0ll;
        for(int i = 0;i < nums.size();i++) {
            int index = v[i].second;
            if(marked[index] == 1) continue;
            answer += v[i].first;
            marked[index] = 1;
            if(index - 1 < 0) marked[0] = 1;
            else marked[index-1] = 1;

            if(index + 1 >= nums.size()) marked[nums.size()-1] = 1;
            else marked[index+1] = 1;
        }
        print(marked);
        return answer;
    }
};