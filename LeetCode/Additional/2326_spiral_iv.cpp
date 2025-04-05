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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>answer(m,vector<int>(n,-1));
        int up = 0; int down = m - 1; int left = 0; int right = n - 1;
        int i = 0;
        ListNode * curr = head;
        while(curr) {
            i = left;
            while(i <= right) {
                if(!curr) return answer;
                answer[up][i] = curr->val; curr = curr->next;
                i++; 
            }
            up++;
            i = up;
            while(i <= down) {
                if(!curr) return answer;
                answer[i][right] = curr->val; curr = curr->next;
                i++;
            }
            right--;

            i = right;
            while(i >= left) {
                if(!curr) return answer;
                answer[down][i] = curr->val; curr = curr->next;
                i--;
            }
            down--;

            i = down;
            while(i >= up) {
                if(!curr) return answer;
                answer[i][left] = curr->val; curr = curr->next;
                i--;
            }
            left++;
        }
        return answer;
    }
};
