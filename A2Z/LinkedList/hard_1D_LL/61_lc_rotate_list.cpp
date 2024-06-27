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

int LL_length(ListNode * head) {
    int count = 0;
    ListNode * curr = head;
    while(curr) {
        count++;
        curr = curr -> next;
    }
    return count;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr) return nullptr;
    int length = LL_length(head);
    k = k % length;
    if(k == 0) return head;
    ListNode * curr = head;
    while(curr->next) curr = curr->next;
    curr->next = head;
    k = length - k;
    while(k--) curr = curr->next;
    head = curr->next;
    curr->next = nullptr;
    return head;
}

ListNode* rotateRight_(ListNode* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    ListNode* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}


int main() {
    vector<int>arr = {1,2};
    ListNode * head = constructLL(arr);
    print(head);
    head = rotateRight(head,1);
    print(head);
}

// if(head == nullptr) return nullptr;
//     int length = LL_length(head);
//     if(k == 0 || (k%length == 0)) return head;
//     length = k % length;
//     ListNode * kthNode = getKthNode(head,length);
//     ListNode * nextNode = nullptr;
//     if(kthNode)
//         nextNode = kthNode->next;
//     kthNode->next = nullptr;
//     ListNode * temp = nextNode;
//     while(temp && temp->next) temp = temp->next;
//     temp->next = head;
//     return nextNode;