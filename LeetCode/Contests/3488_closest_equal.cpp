// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();
//         map<int,set<int>>mp;
//         for(int i = 0;i < n;i++) {
//             mp[nums[i]].insert(i);
//         }

//         vector<int>answer(queries.size());
//         for(int i = 0;i < queries.size();i++) {
//             int ele = nums[queries[i]];
//             auto it = mp[ele].lower_bound(queries[i]);
//             if(mp[ele].size() == 1) { answer[i] = -1; continue; }
//             auto itend = mp[ele].end(); --itend;
//             if(it == itend) {
//                 int start = *mp[ele].begin();
//                 int index = *it;
//                 int mini = min(abs(index - start), n - abs(index - start));
//                 --it;
//                 mini = min({mini,abs(*it - index), n - abs(*it - index)});
//                 answer[i] = mini;
//             }
//             else if(it == mp[ele].begin()) {
//                 int end = *itend;
//                 int index = *it;
//                 int mini = min(abs(index - end), n - abs(index - end));
//                 ++it;
//                 mini = min({mini,abs(*it - index), n - abs(*it - index)});
//                 answer[i] = mini;
//             }
//             else {
//                 int index = *it;
//                 auto itminus = --it;
//                 auto itplus = ++it; ++itplus;
//                 // cout << *itminus << " " << *itplus << " " << index << endl;
//                 int mini = min(abs(index - *itminus), n - abs(index - *itminus));
//                 mini = min({mini,abs(index - *itplus), n - abs(index - *itplus)});
//                 // cout << mini << endl;
//                 answer[i] = mini;
//             }
//         }
//         return answer;
//     }
// };

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        vector<int> ans;
        vector<int> left(nums.size()), right(nums.size());
        
        unordered_map<int,int> start,end;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                left[i]=-1;
                start[nums[i]]=i;
            }
            else
            {
                left[i]=m[nums[i]];
            }
            m[nums[i]]=i;
        }
        
        m.clear();
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(m.find(nums[i])==m.end())
            {
                right[i]=-1;
                end[nums[i]]=i;
            }
            else
            {
                right[i]=m[nums[i]];
            }
            m[nums[i]]=i;
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int res=INT_MAX;
            
            if(left[queries[i]]!=-1) 
                res=min(res,abs(queries[i]-left[queries[i]]));
            
            if(right[queries[i]]!=-1) 
                res=min(res,abs(queries[i]-right[queries[i]]));
            
            if(start.find(nums[queries[i]])!=start.end() && start[nums[queries[i]]]!=queries[i])
            {
                // res=min(res,abs(queries[i]-start[queries[i]]));
                res=min(res,(int)nums.size()-abs(queries[i]-start[nums[queries[i]]]));
            }
            
            if(end.find(nums[queries[i]])!=end.end() && end[nums[queries[i]]]!=queries[i])
            {
                // res=min(res,abs(queries[i]-end[queries[i]]));
                res=min(res,(int)nums.size()-abs(queries[i]-end[nums[queries[i]]]));
            }
            
            if(res==INT_MAX) res=-1;
            
            ans.push_back(res);
        }
        
        return ans;
    }
};
