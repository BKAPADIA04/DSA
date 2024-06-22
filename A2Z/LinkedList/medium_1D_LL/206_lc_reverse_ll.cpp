#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * constructLL(vector<int>& arr) {
    // code here
    int n = arr.size();
    if (n == 0) {
        return nullptr; // Handle empty input vector
    }
    ListNode * head = new ListNode (arr[0]);
    head -> next = nullptr;

    ListNode * temp =  head;
    for(int i = 1;i < n;i++) {
        ListNode  * curr = new ListNode (arr[i]);
        temp->next = curr;
        temp = temp->next;
    }
    return head;
}

ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return head;
    // ListNode * prev = nullptr;
    // ListNode * curr = head;
    // ListNode * lead = curr -> next;
    // while(lead) {
    //     curr->next = prev;
    //     prev = curr;
    //     curr = lead;
    //     lead = lead -> next;
    // }
    // curr->next = prev;
    // head = curr;
    // return head;

    // or
    ListNode * prev = nullptr;
    ListNode * curr = head;
    while(curr) {
        ListNode * lead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = lead;
    }
    head = prev;
    return head;
}

void print(ListNode * head) {
    ListNode * temp =  head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int>arr = {1,2,3,4,5};
    ListNode * head = constructLL(arr);
    head = reverseList(head);
    print(head);
}

