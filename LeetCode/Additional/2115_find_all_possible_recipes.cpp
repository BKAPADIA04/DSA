class Solution {
public:

    void print(vector<string>v) {
        for(auto it:v) {
            cout << it << " ";
        }
        cout << endl;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>mp; int counter = 0;
        for(int i = 0;i < recipes.size();i++) {
            if(mp.find(recipes[i]) == mp.end()) mp[recipes[i]] = counter++;
        }
        for(int i = 0;i < ingredients.size();i++) {
            for(int j = 0;j < ingredients[i].size();j++) {
                if(mp.find(ingredients[i][j]) == mp.end()) mp[ingredients[i][j]] = counter++;
            }
        }
        set<int>supplies_set;
        for(int i = 0;i < supplies.size();i++) {
            if(mp.find(supplies[i]) == mp.end()) mp[supplies[i]] = counter++;
            supplies_set.insert(mp[supplies[i]]);
        }
        

        vector<vector<int>>adj(mp.size());
        vector<int>indegree(mp.size());
        for(int i = 0;i < recipes.size();i++) {
            int recipe_no = mp[recipes[i]];
            for(int j = 0;j < ingredients[i].size();j++) {
                int ingre_no = mp[ingredients[i][j]];
                adj[ingre_no].push_back(recipe_no);
                indegree[recipe_no]++;
            }
        }

        queue<int>q;
        vector<int>visited(mp.size());
        for(int i = 0;i < indegree.size();i++) {
            if(indegree[i] == 0 && (supplies_set.find(i) != supplies_set.end())) {
                q.push(i);
                visited[i] = 1;
            }
        }
    
        while(!q.empty()) {
            int ingre = q.front();
            q.pop();

            for(auto it:adj[ingre]) {
                indegree[it]--;
                if(indegree[it] == 0 && !visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }

        vector<string>answer;
        for(int i = 0;i < recipes.size();i++) {
            int recipe_no = mp[recipes[i]];
            if(visited[recipe_no]) answer.push_back(recipes[i]);
        }

        // print(answer);
        return answer;
    }
};
