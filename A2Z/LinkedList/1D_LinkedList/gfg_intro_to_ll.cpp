#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// struct Node {
//     int data;
//     struct Node * next;
// };


struct Node* print(struct Node* head) {
    struct Node * temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    return NULL;
}

struct Node* constructLL(vector<int>& arr) {
    // code here
    int n = arr.size();
    if (arr.empty()) {
        return nullptr; // Handle empty input vector
    }
    // struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    Node* head = new Node(arr[0]);
    // head -> data = arr[0];
    head -> next = nullptr;

    Node* temp =  head;
    for(int i = 1;i < n;i++) {
        Node * curr = new Node(arr[i]);
        // curr->data = arr[i];
        curr->next = nullptr;
        temp->next = curr;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int>arr = {1,2,3,4,5};
    struct Node * head = constructLL(arr);
    print(head);
}


