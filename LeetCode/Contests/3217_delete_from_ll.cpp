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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>umap;
        for(int i = 0;i < nums.size();i++) {
            umap[nums[i]]++;
        }

        if(head == nullptr || (head->next == nullptr && umap.count(head->val) > 0)) return nullptr;
        ListNode * prev = nullptr; ListNode * curr = head;
        while(curr != nullptr) {
            int ele = curr->val;
            if(umap.count(ele)) {
                if(prev) {
                    prev->next = curr->next;
                }
                else {
                    head = curr->next;
                }
            }
            else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
