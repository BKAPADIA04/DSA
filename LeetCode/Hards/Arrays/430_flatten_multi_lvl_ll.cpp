/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * curr = head;
        while(curr) {
            if(curr->child != nullptr) {
                Node * lead = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                while(curr->next) curr = curr->next;
                if(lead) {
                    curr->next = lead;
                    lead->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
