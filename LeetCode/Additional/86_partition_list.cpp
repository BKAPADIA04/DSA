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

    void print(ListNode * curr) {
        ListNode * temp = curr;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode * leftHead = new ListNode(-1);
        ListNode * rightHead = new ListNode(-1);

        ListNode * curr = head;
        ListNode * left = leftHead, *right = rightHead;
        while(curr) {
            int value = curr->val;
            if(value < x) {
                left->next = curr;
                left = left->next;
            }
            else {
                right->next = curr;
                right = right->next;
            }
            curr = curr->next;
        }

        right->next = nullptr;
        left->next = rightHead->next;
        // print(leftHead);
        // print(rightHead);

        // left->next = rightHead->next;
        return leftHead->next;
    }
};
