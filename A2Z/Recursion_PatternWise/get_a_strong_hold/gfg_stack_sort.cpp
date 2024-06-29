#include <bits/stdc++.h>
using namespace std;


class SortedStack{
public:
	stack<int> s;
	void sort();
};

void print(stack<int>st){
    if(st.empty()) return;
    int element = st.top();
    cout << element << endl;
    st.pop();
    print(st);
    // cout << endl;
}

void insert_at_place(stack<int>&s,int x) {
    if(s.empty() || x >= s.top()) s.push(x);
    else {
        int top = s.top();
        s.pop();
        insert_at_place(s,x);
        s.push(top);
    }
}

void SortedStack :: sort() {
    if(s.empty()) return ;
    int ele = s.top();
    s.pop();
    sort();
    insert_at_place(s,ele);
}

int main() {
    SortedStack obj = SortedStack();
    obj.s.push(11);obj.s.push(2);obj.s.push(32);obj.s.push(3);obj.s.push(41);
    // print(obj.s);
    obj.sort();
    print(obj.s);
}