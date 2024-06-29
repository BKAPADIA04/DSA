#include <bits/stdc++.h>
using namespace std;

void print(stack<int>st){
    if(st.empty()) return;
    int element = st.top();
    cout << element << " " ;
    st.pop();
    print(st);
}

void insert_at_bottom(stack<int>&st,int x) {
    if(st.empty()) st.push(x);
    else {
        int ele = st.top();
        st.pop();
        insert_at_bottom(st, x);
        
        st.push(ele);
    }
}


void Reverse(stack<int> &st){
    if(st.empty()) return;
    int data = st.top();
    st.pop();
    Reverse(st);
    insert_at_bottom(st,data);
}

int main() {
    stack<int>st;
    st.push(1);st.push(2);st.push(3);
    print(st);
    Reverse(st);
    print(st);
}