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


    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode * prev = dummy;
        ListNode * curr = head;
        while(curr) {
            if(curr->next) {
                if(curr->val == curr->next->val) {
                    int value = curr->val;
                    while(curr && curr->val == value) {
                        curr = curr->next;
                    }
                    if(curr == nullptr) prev->next = nullptr;
                }
                else {
                    prev->next = curr;
                    prev = curr;
                    curr = curr->next;
                }
            }
            else {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
