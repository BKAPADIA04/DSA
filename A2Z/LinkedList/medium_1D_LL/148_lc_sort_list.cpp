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

vector<ListNode *> middleNode(ListNode * head) {
    if(head->next == nullptr) return {head,nullptr};
    ListNode * prev = nullptr;
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        // Move slow one step.
        slow = slow->next; 
        // Move fast two steps.
        fast = fast->next->next; 
    }
    prev->next = nullptr;
    return {head,slow};
}

ListNode * merge(ListNode * head1,ListNode * head2) {
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    ListNode * curr1 = head1;
    ListNode * curr2 = head2;

    ListNode * mergedHead = nullptr;
    ListNode * curr = nullptr;

    while(curr1 && curr2) {
        if(curr1->val < curr2->val) {
            if(mergedHead == nullptr) mergedHead = curr1;
            else { curr->next = curr1; }
            curr = curr1;
            curr1 = curr1->next;
        }
        else {
            if(mergedHead == nullptr) mergedHead = curr2;
            else { curr->next = curr2; }
            curr = curr2;
            curr2 = curr2->next;
        }
    }
    curr->next = (curr1 != nullptr) ? curr1 : curr2;
    return mergedHead;
}

ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    vector<ListNode *> middle = middleNode(head);
    ListNode * leftHead = middle[0];
    ListNode * rightHead = middle[1];

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return merge(leftHead,rightHead);
}


int main() {
    vector<int>arr = {-1,-2,100,0};
    ListNode * head = constructLL(arr);
    ListNode * ans = sortList(head);
    // head = middleNode(head);
    print(ans);

}