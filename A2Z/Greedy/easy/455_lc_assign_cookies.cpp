#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    if(s.size() == 0 || g.size() == 0) return 0;
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());

        int count = 0; int i = 0,j = 0;
        while(i < g.size() && j < s.size()) {
            while(i < g.size() && s[j] < g[i]) i++;
            if(i < g.size() && s[j] >= g[i]) { count++; j++; i++;}
        }
        return count;
}

// or 
int findContentChildren_(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
    
        int child = 0;
        int cookie = 0;
        while(child < g.size() && cookie < s.size()){
            if(s[cookie] >= g[child]){
              
                child++;
               
            }
                cookie++;
            
        }
        return child;
    }

int main() {
    vector<int>g = {1,2,3};
    vector<int>s {1,1};
    cout << findContentChildren(g,s) << endl;
}