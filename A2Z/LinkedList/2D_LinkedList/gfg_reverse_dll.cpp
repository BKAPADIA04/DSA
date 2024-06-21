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
    Node * temp = head;
    while(temp) {
        temp->prev = temp->next;
    }
    return head;
}