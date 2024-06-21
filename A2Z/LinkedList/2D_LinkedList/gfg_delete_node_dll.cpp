#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

void print(Node * head) {
    Node * temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    while(temp->next) {
        // cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;

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



Node* deleteNode(Node* head, int x) {
    if(head == nullptr) {
        return nullptr;
    }
    Node * curr = head;
    int i = 1;
    while(curr) {
        if(i == x) break;
        i++;
        curr = curr -> next;
    }
    // cout << curr->data << endl;
    
    if(curr->prev == nullptr) { head = curr->next; head->prev = nullptr;}
    else if(curr->next == nullptr) { curr->prev->next = nullptr;}
    else { curr->prev->next = curr->next; curr->next->prev = curr->prev;}
    delete curr;
    return head;
}

int main() {
    
    vector<int>arr = {1,3,4};
    Node * head = constructDLL(arr);
    head = deleteNode(head,3);
    print(head);
}
