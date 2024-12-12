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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * newNode = new TreeNode(val);
        if(root == nullptr) {
            root = newNode;
            return root;
        }
        TreeNode * node = root; TreeNode * prev = nullptr;
        while(node) {
            prev = node;
            if(node->val < val) node = node->right;
            else node = node->left;
        }
        if(prev->val < val) prev->right = newNode;
        else prev->left = newNode;

        return root;
    }
};