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


void deleteAllOccurOfX(struct Node** head_ref, int x) {
    Node * head = *head_ref;
    Node * curr = *head_ref;
    // cout << (*head_ref)->data << endl;
    while(curr) {
        if(curr->data == x) {
            if(curr->prev == nullptr) {
                *head_ref = curr->next;
                if (*head_ref) {
                    (*head_ref)->prev = nullptr; 
                }
            }
            else if(curr->next == nullptr) {
                curr->prev->next = nullptr;
            }
            else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
        }
        curr = curr -> next;
    }
}

int main() {
    vector<int>arr = {9,1,3,4,5,1,8,4};
    Node * head = constructDLL(arr);
    print(head);
    deleteAllOccurOfX(&head,9);
    print(head);
}