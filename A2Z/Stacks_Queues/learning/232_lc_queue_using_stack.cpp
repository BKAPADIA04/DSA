#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:

    stack<int>input,output;
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.size() == 0) {
            while(input.size() != 0) {
                output.push(input.top());
                input.pop();
            }
        }
        int ele = output.top();
        output.pop();
        return ele;
    }
    
    int peek() {
        if(output.size() == 0) {
            while(input.size() != 0) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return !(input.size() + output.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */