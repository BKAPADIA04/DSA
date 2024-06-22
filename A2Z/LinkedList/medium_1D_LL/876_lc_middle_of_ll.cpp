#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode * slow = head;
    ListNode * fast = head;
    while(fast && fast->next && fast->next->next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }     
    if(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

    // or
    // while (fast != NULL && fast->next != NULL) {
    //     // Move slow one step.
    //     slow = slow->next; 
    //      // Move fast two steps.
    //     fast = fast->next->next; 
    // }
    // return slow;
}

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

int main() {
    vector<int>arr = {1,2,3,4,5,6};
    ListNode * head = constructLL(arr);
    head = middleNode(head);
    print(head);
}