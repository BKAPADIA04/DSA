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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * prev = dummy;
        ListNode * curr = head;
        while(curr) {
            if(curr->next == nullptr) {
                return dummy->next;
            }
            ListNode * next = curr->next;
            ListNode * lead = next->next;

            prev->next = next;
            next->next = curr;
            curr->next = lead;

            prev = curr;
            curr = lead;
        }
        return dummy->next;
    }
};
