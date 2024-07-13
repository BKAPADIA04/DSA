#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<long long> st;
    long long mini;

    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long val_ = val;
        if(val_ < mini) {
            st.push(2 * val_ - mini);
            mini = val_;
        }
        else {
            st.push(val_);
        }
    }
    
    void pop() {
        if(st.top() < mini) {
            mini = 2 * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */