void MyQueue:: push(int x)
{
    // Your Code
    QueueNode *newNode = new QueueNode(x);
    if(front == nullptr && rear == nullptr) {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    // Your Code 
    if(front == nullptr && rear == nullptr) return -1;
    
    if(front == rear) {
        int ele = front -> data;
        front = front -> next;
        rear = rear -> next;
        return ele;
    }
    
    // if(front == rear && front!=nullptr) return -1;
    
    int ele = front->data;
    front = front->next;
    return ele;
}