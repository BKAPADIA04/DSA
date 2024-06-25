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

int lengthCount(ListNode *headA, ListNode *headB) {
    ListNode * currA = headA;
    ListNode * currB = headB;

    int lengthA = 0; int lengthB = 0;
    while(currA || currB) {
        if(currA) {
            lengthA++;
            currA = currA -> next;
        }
        if(currB) {
            lengthB++;
            currB = currB -> next;
        }
    }
    return lengthA - lengthB;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode * currA = headA;
    ListNode * currB = headB;
    int diff = lengthCount(headA,headB);

    if(diff > 0) {
        while(diff--) currA = currA -> next;
    }
    else {
        while(diff++) currB = currB -> next;
    }

    while(currA != nullptr) {
        if(currA == currB) return currA;
        currA = currA->next;
        currB = currB->next;
    }
    return currA;
}


int main() {
    vector<int>arr1 = {1,2,3,4};
    ListNode * headA = constructLL(arr1);

    vector<int>arr2 = {3,4};
    ListNode * headB = constructLL(arr2);

    cout << lengthCount(headA,headB) << endl;

}