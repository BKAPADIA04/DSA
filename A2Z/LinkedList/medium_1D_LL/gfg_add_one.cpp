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
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return head;
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

ListNode * addOne(ListNode * head) {
    head = reverseLL(head);
    ListNode * curr = head;
    int carry = 1;
    while(curr) {
        int check = curr->val + carry;
        if(check == 10) {
            curr->val = 0;
        }
        else {
            curr->val = check;
            carry = 0;
            head = reverseLL(head);
            return head;
        }
        curr = curr -> next;
    }
    if(carry == 1) {
        head = reverseLL(head);
        ListNode * front = new ListNode(1);
        front->next = head;
        head = front;
    }
    return head;
}

int carryFunction(ListNode * head) {
    if(head == nullptr) return 1;
    int carry = carryFunction(head -> next);
    head -> val = head -> val + carry;
    if(head->val < 10) return 0;
    else head -> val = 0;
    return 1;
}

ListNode * addOne_Recursion(ListNode * head) {
    if(head == nullptr) return head;
    if(carryFunction(head) == 1) {
        ListNode * front = new ListNode(1);
        front->next = head;
        head = front;
        return head;
    }
    return head;
}

int main() {
    vector<int>arr = {9};
    ListNode * head = constructLL(arr);
    // print(head);
    // head = addOne(head);
    head = addOne_Recursion(head);
    print(head);
}