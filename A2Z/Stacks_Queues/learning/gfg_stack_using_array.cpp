#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack :: push(int x) {
    // Your Code
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack :: pop() {
    // Your Code
    if(top == -1)
        return top;
    int ele = arr[top--];
    return ele;
}


int main() {
    MyStack *sq = new MyStack();
    // vector<int>nums = {1,2,1,3,2,1,4,2};
    // for(int i = 0;i < nums.size();i++) {
    //     int QueryType = nums[i++];
    //     if(QueryType == 1) { int a = nums[i++]; sq->push(a); }
    //     else if(QueryType == 2) cout << sq->pop() << " ";
    // }
    // cout << endl;
    // delete sq;

    sq->push(45);
    sq->push(18);
    cout << sq->pop() << endl;
    cout << sq->pop() << endl;
    cout << sq->pop() << endl;
}
