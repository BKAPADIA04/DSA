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

void print(ListNode * head) {
    ListNode * temp =  head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == nullptr) return nullptr;
    ListNode * slow = head;
    ListNode * fast = head; 
    int i = 0; 
    while(i < n) {
        fast = fast->next;
        i++;
    }  
    if(fast == nullptr) {
        head = slow->next;
        return head;
    }
    // cout << i << endl;  
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;   
}


int main() {
    vector<int>arr = {1,2};
    ListNode * head = constructLL(arr);
    head = removeNthFromEnd(head,1);
    print(head);
}