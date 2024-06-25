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

ListNode* deleteMiddle(ListNode* head) {
    if(head == nullptr || head->next == nullptr) { delete head; return nullptr;}
    ListNode * prev = nullptr;
    ListNode * slow = head;   
    ListNode * fast = head;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = nullptr;
    delete slow;
    return head;
}

int main() {
    vector<int>arr = {2,1,2,3,1};
    ListNode * head = constructLL(arr);
    head = deleteMiddle(head);
    print(head);
}
