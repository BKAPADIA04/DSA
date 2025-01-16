class Solution {
public:

    void print(unordered_map<string,int>m) {
        for(auto it:m) cout << it.first << " " << it.second << endl ;
        cout << endl;
    }

    int find(vector<int>&par,int X) {
        if(par[X] == X) return X;
        else return par[X] = find(par,par[X]);
    }
    
    void unionbySize(vector<int>&par,vector<int>&size,int X,int Y) {
        int ult_x = find(par,X);
        int ult_y = find(par,Y);
        if(ult_x == ult_y) return;
        
        if(size[ult_x] < size[ult_y]) {
            par[ult_x] = ult_y;
            size[ult_y] += size[ult_x];
        }
        else {
            par[ult_y] = ult_x;
            size[ult_x] += size[ult_y];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>m;
        vector<int>par(accounts.size()); vector<int>size(accounts.size());
        for(int i = 0;i < accounts.size();i++) {
            par[i] = i;
        }
        for(int i = 0;i < accounts.size();i++) {
            for(int j = 1;j < accounts[i].size();j++) {
                if(m.find(accounts[i][j]) == m.end())
                    m[accounts[i][j]] = i;
                else {
                    unionbySize(par,size,i,m[accounts[i][j]]);
                }
            }
        }
        // print(m);
        vector<vector<string>>answer(accounts.size());
        
        for(auto it:m) {
            string email = it.first;
            int index = it.second;

            if(find(par,index) == index) {
                answer[index].push_back(email);
            }
            else {
                answer[par[index]].push_back(email);
            }
        }

        vector<vector<string>>ans;
        for(int i = 0;i < accounts.size();i++) {
            if(answer[i].size() == 0) continue;
            vector<string>temp; temp.push_back(accounts[i][0]);
            sort(answer[i].begin(),answer[i].end());
            for(auto it:answer[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;



    }
};