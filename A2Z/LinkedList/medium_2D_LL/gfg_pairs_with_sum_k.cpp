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


vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> answer;
    Node * low = head;
    Node * high = head;
    while(high -> next) high = high->next;
    while(low->data < high->data) {
        int sum = low->data + high->data;
        if(sum == target) answer.push_back(make_pair(low->data,high->data));
        if(sum > target) high = high->prev;
        else low = low->next;
    }
    return answer;
}

int main() {
    vector<int>arr = {1,5,6};
    Node * head = constructDLL(arr);
    int target = 6;
    print(head);
    vector<pair<int, int>> answer = findPairsWithGivenSum(head,target);
    for(auto it:answer) {
        cout << it.first << " " << it.second << endl;
    }
}