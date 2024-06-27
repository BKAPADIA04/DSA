#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        val = x;
        next = NULL;
        bottom = NULL;
    }

};

Node * constructLL(vector<int>& arr) {
    // code here
    int n = arr.size();
    if (n == 0) {
        return nullptr; // Handle empty input vector
    }
    Node * head = new Node (arr[0]);
    head -> bottom = nullptr;

    Node * temp =  head;
    for(int i = 1;i < n;i++) {
        Node  * curr = new Node (arr[i]);
        temp->bottom = curr;
        temp = temp->bottom;
    }
    return head;
}

void printB(Node * head) {
    Node * temp =  head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->bottom;
    }
    cout << endl;
}
void printH(Node * head) {
    Node * temp =  head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node * merge(Node * head1,Node * head2) {
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    Node * curr1 = head1;
    Node * curr2 = head2;

    Node * mergedHead = nullptr;
    Node * curr = nullptr;

    while(curr1 && curr2) {
        if(curr1->val < curr2->val) {
            if(mergedHead == nullptr) mergedHead = curr1;
            else { curr->bottom = curr1; }
            curr = curr1;
            curr1 = curr1->bottom;
        }
        else {
            if(mergedHead == nullptr) mergedHead = curr2;
            else { curr->bottom = curr2; }
            curr = curr2;
            curr2 = curr2->bottom;
        }
    }
    curr->bottom = (curr1 != nullptr) ? curr1 : curr2;
    return mergedHead;
}

Node * flatten(Node * head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node * mergedHead = nullptr;
    Node * curr = head;
    while(curr) {
        Node * curr_next = curr->next;
        curr->next = nullptr;
        mergedHead = merge(mergedHead,curr);
        curr = curr_next;
    }
    return mergedHead;
}

int main() {
    vector<int>arr1 = {5,7,8,30};
    Node * head1 = constructLL(arr1);
    // printB(head1);
    vector<int>arr2 = {10};
    Node * head2 = constructLL(arr2);
    // printB(head2);
    vector<int>arr3 = {19,22,50};
    Node * head3 = constructLL(arr3);
    // printB(head3);
    vector<int>arr4 = {28,35,40,45};
    Node * head4 = constructLL(arr4);
    // printB(head4);
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    // printH(head1);
    Node * ans = flatten(head1);
    printB(ans);
}

// if(root == nullptr || root->next == nullptr) return root;
//     Node * mergedHead = root;
//     Node * curr = root->next;
//     if(root->next)
//         Node * curr_next = root->next->next;

//     mergedHead->next = nullptr; curr->next = nullptr;
//     printB(mergedHead);printB(curr);
//     mergedHead = merge(mergedHead,curr);
//     printB(mergedHead);
//     while(curr) {
//         Node * curr = root->next;
        
//     }
//     return nullptr;