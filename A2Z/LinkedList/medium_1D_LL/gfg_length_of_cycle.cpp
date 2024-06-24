#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * constructLL(vector<int>& arr,int pos) {
    // code here
    int n = arr.size();
    if (n == 0) {
        return nullptr; // Handle empty input vector
    }
    ListNode * lastRay = new ListNode();
    ListNode * head = new ListNode (arr[0]);
    head -> next = nullptr;
    if(pos == 0) lastRay = head;
    ListNode * temp =  head;
    for(int i = 1;i < n;i++) {
        ListNode  * curr = new ListNode (arr[i]);
        temp->next = curr;
        temp = temp->next;
        if(pos == i) lastRay = curr;
    }
    temp->next = lastRay;
    return head;
}

int countNodesinLoop(ListNode *head) {
    ListNode * slow = head;
    ListNode * fast = head;
    ListNode * start = nullptr;
    int count = 1;

    while(fast && fast->next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow -> next;
                fast = fast -> next;
            }
            start = slow -> next;
            while(start != slow) {
                count++;
                start = start -> next;
            }
            return count;
        }
    }
    return 0;
}


int main() {
    vector<int>arr = {25,14,19,33,10,21,39,90,58,45};
    int pos = -1;
    ListNode * head = constructLL(arr,pos);
    cout << countNodesinLoop(head) << endl;
}