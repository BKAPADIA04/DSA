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
        ListNode * curr = head, * prev = nullptr;
        while(curr) {
            ListNode * lead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = lead;
        }
        return prev;
    } 

    ListNode * getKthNode(ListNode * head, int k) {
        ListNode * curr = head;
        k--;
        while(curr && k) {
            curr = curr -> next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * curr = head;
        ListNode * prev = nullptr;
        while(curr) {
            ListNode * kthNode = getKthNode(curr, k);
            if(kthNode == nullptr) {
                if(prev) prev->next = curr;
                break;
            }
            ListNode * lead = kthNode->next;
            kthNode -> next = nullptr;
            reverseLL(curr);

            if(curr == head) {
                head = kthNode; 
            }
            else {
                prev->next = kthNode;
            }

            prev = curr;
            curr = lead;
        }
        return head;
    }
};
