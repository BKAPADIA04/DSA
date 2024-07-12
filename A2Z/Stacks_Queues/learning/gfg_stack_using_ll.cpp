//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // Your Code
    StackNode *newTop = new StackNode(x);
    if(top == nullptr) { top = newTop; return;}
    newTop->next = top;
    top = newTop;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top == nullptr) {
        return -1;
    }
    
    int ele = top->data;
    top = top->next;
    return ele;
}