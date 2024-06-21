#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

void addNode(Node *head, int pos, int data)
{
    if(head == nullptr) {
        head = new Node(data);
        return;
    }
    // cout << head -> data << endl;
    Node * curr = head;
    int i = 0;
    while(curr) {
        if(i == pos) break;
        i++;
        curr = curr -> next;
    }

    Node * node = new Node(data);
    if(curr->next) { node -> next = curr -> next; curr->next->prev = node;}
    curr->next = node;
    node->prev = curr;  
}

void print(Node * head) {
    Node * temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // temp = head;
    // while(temp->next) {
    //     // cout << temp->data << " ";
    //     temp = temp->next;
    // }
    // while(temp) {
    //     cout << temp->data << " ";
    //     temp = temp->prev;
    // }
    // cout << endl;

}


Node* constructDLL(vector<int>& arr) {
    // code here
    int n = arr.size();
    if(n == 0) return nullptr;
    Node * head = new Node(arr[0]);
    if(n == 1) return head;

    Node * temp = head;
    for(int i = 1;i < n; i++) {
        Node * curr = new Node(arr[i]);
        temp -> next = curr;
        curr -> prev = temp;
        temp = curr;
    }
    temp->next = nullptr;
    return head;
}

Node* reverseDLL(Node * head)
{
    if (!head || !head->next) { 
        return head;
    }
    Node * curr = head;
    Node * temp = nullptr;
    while(curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    curr = head;
    while(curr->prev) {
        curr = curr->prev;
    }
    head = curr;
    return head;
}

int main() {
    
    vector<int>arr = {1,2,3,4};
    Node * head = constructDLL(arr);
    // addNode(head,1,27);
    print(head);
    head = reverseDLL(head);
    print(head);
}

