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

ListNode * reverseLL(ListNode * head) {
    ListNode * prev = nullptr;
    ListNode * curr = head;
    while(curr) {
        ListNode * lead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = lead;
    }
    return prev;
}

ListNode * getKthNode(ListNode * node,int k) {
    k = k - 1;
    ListNode * temp = node;
    while(temp && k--) {
        temp = temp -> next;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode * curr = head;
    ListNode * prev = nullptr;
    while(curr) {
        ListNode * kthNode = getKthNode(curr,k);
        if(kthNode == nullptr) {
            if(prev)
                prev->next = curr;
            break;
        }
        ListNode * next = kthNode->next;
        kthNode -> next = nullptr;
        reverseLL(curr);
        
        if(curr == head) {
            head = kthNode;
        }
        else {
            prev->next = kthNode;
        }
        prev = curr;
        curr = next;
    }
    return head;
}

int main() {
    vector<int>arr = {1,2,3,4,5};
    ListNode * head = constructLL(arr);
    // head = reverseList(head);
    // head = reverseLL(head);
    print(head);
    ListNode * ans = reverseKGroup(head,2);
    print(ans);
}