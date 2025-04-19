/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void print(ListNode * head) {
        ListNode * curr = head;
        while(curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    ListNode * reverseLL(ListNode * head) {
        ListNode * curr = head, * prev = nullptr;
        while(curr) {
            ListNode * lead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = lead;
        }
        return prev;
    } 

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * prev = nullptr; ListNode * curr = head; 
        ListNode * later = nullptr;
        
        int counter = 1;
        while(curr) {
            if(left == counter) break;
            prev = curr;
            curr = curr->next;
            counter++;
        }
        curr = head;
        later = curr->next;
        counter = 1;
        while(curr) {
            if(right == counter) break;
            curr = curr->next;
            later = curr->next;
            counter++;
        }

        curr -> next = nullptr;
        ListNode * start = (prev == nullptr) ? head : prev->next;
        
        ListNode * revLL = reverseLL(start);

        if(prev) {
            prev->next = revLL;
            ListNode * temp = prev;
            while(temp->next) temp = temp->next;
            temp->next = later;
        }
        else {
            ListNode * temp = revLL;
            while(temp->next) temp = temp->next;
            temp->next = later;
            return revLL;
        }

        return head;
    }
};
