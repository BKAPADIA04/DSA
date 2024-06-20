#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = nullptr; }
};

bool searchKey(int n, struct Node* head, int key) {
    // Code here
    Node*temp = head;
    while(temp) {
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}