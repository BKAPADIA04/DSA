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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * dummy = new ListNode();
    ListNode * temp = dummy;
    int carry = 0;
    while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
    return dummy -> next; 
}

ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry) {
        // Base case: if both nodes are null and no carry, return null
        if (!l1 && !l2 && carry == 0) return nullptr;

        // Calculate the sum and the new carry
        int sum = carry;
        if (l1) sum += l1->val;
        if (l2) sum += l2->val;
        carry = sum / 10;

        // Create a new node with the digit part of the sum
        ListNode* result = new ListNode(sum % 10);

        // Recur for the next nodes
        result->next = addTwoNumbersHelper(
            l1 ? l1->next : nullptr,
            l2 ? l2->next : nullptr,
            carry
        );

        return result;
    }

    ListNode* addTwoNumbers_(ListNode* l1, ListNode* l2) {
       return addTwoNumbersHelper(l1, l2, 0);
    }



int main() {
    vector<int>arr1 = {5};
    ListNode * head1 = constructLL(arr1);
    vector<int>arr2 = {5};
    ListNode * head2 = constructLL(arr2);
    ListNode * ans = addTwoNumbers(head1,head2);
    print(ans);
}
