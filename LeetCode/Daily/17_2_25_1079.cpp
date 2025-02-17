
class Solution {
public:

    // void print(unordered_set<string>s) {
    //     for(auto it:s) cout << it << " ";
    //     cout << endl;
    // }
    // vector<int>factorial() {
    //     vector<int>fact(10,0);
    //     fact[0] = 1;
    //     for(int i = 1;i < 8;i++) {
    //         fact[i] = fact[i-1] * i;
    //     }
    //     return fact;
    // }

    // void check(unordered_set<string>&s,string &temp,string tiles,vector<int>&visited) {
    //     if(s.find(temp) != s.end()) return;
    //     else {
    //         if(temp != "")
    //             s.insert(temp);
    //     }

    //     for(int i = 0;i < tiles.size();i++) {
    //         if(!visited[i]) {
    //             visited[i] = 1;
    //             temp.push_back(tiles[i]);
    //             check(s,temp,tiles,visited);
    //             temp.pop_back();
    //             visited[i] = 0;
    //         }
    //     }
    //     // print(s);
    // }


    // int numTilePossibilities(string tiles) {
    //     int n = tiles.size();
    //     // vector<int>fact = factorial();
    //     unordered_set<string>s; vector<int>visited(n,0);
    //     string temp = "";
    //     check(s,temp,tiles,visited);
    //     return s.size();
    // }

    vector<int>fact;

    void factorial() {
        fact.resize(10);
        fact[0] = 1;
        for(int i = 1;i < 8;i++) {
            fact[i] = fact[i-1] * i;
        }
    }

    int check(unordered_set<string>&s,string &tiles,string &temp,int index) {
        if(index >= tiles.size()) {
            if(s.find(temp) == s.end()) { s.insert(temp); return countPerm(temp); }
            return 0;
        }

        int notTaken = check(s,tiles,temp,index+1);
        temp.push_back(tiles[index]);
        int taken = check(s,tiles,temp,index+1);
        temp.pop_back();

        return taken + notTaken;
    }

    int countPerm(string temp) {
        unordered_map<char,int>m;
        for(int i = 0;i < temp.size();i++) {
            m[temp[i]]++;
        }
        
        int num = fact[temp.size()];
        for(auto it:m) {
            num /= fact[it.second];
        }
        return num;
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        factorial();
        unordered_set<string>s; string temp = "";
        return check(s,tiles,temp,0) - 1;
    }
};
