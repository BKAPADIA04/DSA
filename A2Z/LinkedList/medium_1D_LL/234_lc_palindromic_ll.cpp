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
    head = prev;
    return head;
}

bool isPalindrome(ListNode * head) {
    int flag = 0;
    ListNode * slow = head;
    ListNode * fast = head;
    while(fast && fast->next && fast->next->next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    ListNode * second = slow->next;
    slow->next = nullptr;
    ListNode * first = head;
    second = reverseLL(second);
    ListNode * temp = second;
    while(temp) {
        if(temp->val != first->val) {flag = 1;break;}
        temp = temp->next;
        first = first->next;
    }
    second = reverseLL(second);
    slow->next = second;

    if(flag) return false;
    return true;
}

int main() {
    vector<int>arr = {1,2,3,2,1};
    ListNode * head = constructLL(arr);
    cout << isPalindrome(head) << endl;
}