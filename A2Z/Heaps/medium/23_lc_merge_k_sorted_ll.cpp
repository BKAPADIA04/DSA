#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
typedef pair<int,int> p;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode();
        int k = lists.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<ListNode*>ks;
        for(int i = 0;i < k;i++) {
            ListNode * tempHead = lists[i];
            ks.push_back(tempHead);
            if(tempHead)
                pq.push({tempHead->val,i});
        }
        ListNode * temp = head;
        int count = 0;
        while(!pq.empty()) {
            // if(pq.empty()) break;
            int ele = pq.top().first;
            int i = pq.top().second;
            ListNode * tempo = new ListNode(ele);
            temp->next = tempo;
            temp = temp->next;
            pq.pop();
            count++;
            if(ks[i]->next != nullptr) {
                ks[i] = ks[i] -> next;
                pq.push({ks[i]->val,i});
            }
        }
        return head->next;
    }
};