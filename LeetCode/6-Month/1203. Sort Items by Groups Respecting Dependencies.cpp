class Solution {
public:

    vector<int>topoSort(vector<unordered_set<int>>&graph, vector<int>&indegree) {
        vector<int> ans;
        queue<int> q;
        for(int i =  0; i <indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            
            ans.push_back(t);
            
            for(int next : graph[t]) {
                --indegree[next];
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        for(int i =  0; i < indegree.size(); i++) {
            if(indegree[i] > 0) return {};
        }
        
        return ans;
    } 

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0;i < n;i++) {
            if(group[i] == -1) group[i] = m++;
        }

        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int>inGroup(m), inItem(n);
        for(int i = 0;i < n;i++) {
            int groupI = group[i];
            for(auto it : beforeItems[i]) {
                int groupIT = group[it];
                if(groupIT != groupI && !graphGroup[groupIT].count(groupI)) {
                    graphGroup[groupIT].insert(groupI);
                    inGroup[groupI]++;
                }

                if(!graphItem[it].count(i)) {
                    graphItem[it].insert(i);
                    inItem[i]++;
                }
            }
        }

        vector<int>topoGroup = topoSort(graphGroup, inGroup);
        vector<int>topoItem = topoSort(graphItem, inItem);

        if(topoGroup.size() == 0 || topoItem.size() == 0) return {};

        vector<vector<int>> group2item(m);
        for(auto item : topoItem){
            group2item[group[item]].push_back(item);
        }

        vector<int> ans;
        for(int group_id : topoGroup) {
            for(int item : group2item[group_id]) {
                ans.push_back(item);
            }
        }

        return ans;
    }
};
