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

    void print(ListNode*head) {
        ListNode * temp = head;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode * reverse(ListNode * head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * lead = curr->next;

        while(lead) {
            curr->next = prev;
            prev = curr;
            curr = lead;
            lead = lead->next;
        }
        curr->next = prev;
        head = curr;
        return head;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int count = 1;
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * last = head;
        ListNode * lead = head;

        while(last) {
            int i = 1;
            for(;i < count;i++) {
                if(last->next == nullptr) {
                    break;
                }
                else {
                    // curr = curr->next;
                    last = last->next;
                }
            }
            lead = last->next;
            if(i % 2 == 0) {
                last->next = nullptr;
                curr = reverse(curr);
                prev->next = curr;
                ListNode * temp = curr;
                while(temp && temp->next) temp = temp->next;
                temp->next = lead;
                last = temp;
                // print(head);
            }
            prev = last;
            curr = last->next;
            last = curr;
            count++;
            // print(head);
        }
        return head;
    }
};
