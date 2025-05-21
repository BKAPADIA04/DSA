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

    ListNode * reverseLL(ListNode * head) {
        ListNode * curr = head;
        ListNode * prev = nullptr;
        while(curr) {
            ListNode * lead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = lead;
        }
        return prev;
    }

    ListNode * addTwoNum(ListNode * head1,ListNode * head2) {
        ListNode * l1 = head1;
        ListNode * l2 = head2;
        int carry = 0;

        ListNode * dummy = new ListNode(-1);
        ListNode * temp = dummy;

        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode * node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        ListNode * ans = addTwoNum(l1,l2);

        return reverseLL(ans);
    }
};
