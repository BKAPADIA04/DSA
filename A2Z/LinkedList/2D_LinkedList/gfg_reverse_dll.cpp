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
    // return curr->prev;
    return head;
}