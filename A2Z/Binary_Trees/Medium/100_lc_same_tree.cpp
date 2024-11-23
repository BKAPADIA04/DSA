/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>q1,q2;
        if(p == nullptr && q == nullptr) return true;
        if((p && !q) || (!p && q)) return false;
        q1.push(p); q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode * n1 = q1.front(); q1.pop(); 
            TreeNode * n2 = q2.front(); q2.pop();

            if(n1->val != n2->val) return false;

            if((n1->left && !n2->left) || (!n1->left && n2->left)) return false;
            if((n1->right && !n2->right) || (!n1->right && n2->right)) return false;

            if(n1->left) q1.push(n1->left); if(n1->right) q1.push(n1->right);
            if(n2->left) q2.push(n2->left); if(n2->right) q2.push(n2->right);
        }
        if(!q1.empty() || !q2.empty()) return false;

        return true;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, they are identical
        if (p == NULL && q == NULL) {
            return true;
        }
        // If only one of the nodes is NULL, they are not identical
        if (p == NULL || q == NULL) {
            return false;
        }
        // Check if values are equal and recursively check left and right subtrees
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        // Values are not equal, they are not identical
        return false;
    }
};