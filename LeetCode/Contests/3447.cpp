class Solution {
public:

    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {

        // TLE
        // map<int,unordered_set<int>>m;
        // for(int i = 0;i < groups.size();i++) {
        //     int ele = groups[i];
        //     if(m.find(ele) != m.end()) continue;
        //     for(int j = 1;j * j <= ele;j++) {
        //         if((ele % j) == 0) { m[ele].insert(j); m[ele].insert(ele/j);}
        //     }
        // }

        // vector<int>answer(groups.size(),-1);
        // for(int i = 0;i < groups.size();i++) {
        //     int ele = groups[i];
        //     for(int j = 0;j < elements.size();j++) {
        //         if(m[ele].find(elements[j]) != m[ele].end()) {
        //             answer[i] = j; break;
        //         }
        //     }
        // }
        // return answer;

        unordered_map<int,int>ele_index;
        for(int i = 0;i < elements.size();i++)  {
            if(!ele_index.count(elements[i])) ele_index[elements[i]] = i;
        }

        vector<int>answer;
        for(int i : groups) {
            int minIndex = INT_MAX;
            for(int j = 1;j * j <= i;j++) {
                if((i % j) == 0) {
                    if(ele_index.count(j)) minIndex = min(minIndex,ele_index[j]);
                    if(j != (i/j) && ele_index.count(i/j)) minIndex = min(minIndex,ele_index[i/j]);
                }
            }
            answer.push_back(minIndex == INT_MAX ? -1 : minIndex);
        }
        return answer;
    }
};
