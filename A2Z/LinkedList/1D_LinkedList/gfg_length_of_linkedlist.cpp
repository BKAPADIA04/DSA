#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = nullptr; }
};

int getCount(struct Node* head){
    //Code here
    Node*temp = head;
    int count = 0;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

