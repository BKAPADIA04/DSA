#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
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

Node * removeDuplicates(struct Node *head)
{
    Node * curr = head;
    Node * temp = head;
    while(curr) {
        while(temp && temp->data == curr->data) temp = temp->next;
        curr->next = temp;
        if(temp)
            temp->prev = curr;
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int>arr = {1,2,2,3,3,4,4};
    Node * head = constructDLL(arr);
    print(head);
    head = removeDuplicates(head);
    print(head);
}