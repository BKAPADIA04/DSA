#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& m, int n) 
{
    stack<int>st;
    for(int i = 0;i < n;i++) st.push(i);
    
    while(st.size() != 1) {
        int i = st.top(); st.pop();
        int j = st.top(); st.pop();
        // i knows j
        if(m[i][j]) st.push(j);
        else st.push(i);
    }

    int celeb_check = st.top(); 
    st.pop();

    for(int i = 0;i < n;i++) {
        if(i == celeb_check) continue;
        if(m[celeb_check][i] || !m[i][celeb_check]) return -1;
    }
    return celeb_check;
}

int main() {
    vector<vector <int> > celeb = {{0,1,0},{0,0,0},{0,1,0}};
    vector<vector <int> > celeb_ = {{0,1},{1,0}};
    cout << celebrity(celeb,3) << endl;
    cout << celebrity(celeb_,2) << endl;
}