#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = nullptr; }
};

//Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x) {
    // Your code here
    Node*temp = new Node(x);
    if(head == NULL) head = temp;
    else { temp->next = head; head = temp;}
    return head;
}


//Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)  {
    // Your code here
    Node*temp = new Node(x);
    if(head == NULL) {
        head = temp;
    }
    else { 
        Node*mover = head;
        while(mover->next != nullptr) {
            mover = mover -> next;
        }
        mover -> next = temp;
    }
    return head;
}

void print(Node *head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node*head = insertAtEnd(NULL,10);
    print(head);
    head = insertAtBegining(head,20);
    print(head);
    head = insertAtEnd(head,30);
    print(head);
}