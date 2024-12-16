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

    TreeNode * delete_node(TreeNode * node) {
        if(node->left == nullptr) return node->right;
        else if(node->right == nullptr) return node->left;
        else {
            TreeNode * rightRoot = node->right;
            TreeNode * inorder_pre = inorder_predecessor(node->left);
            inorder_pre->right = rightRoot;
        }
        return node->left;
    }

    TreeNode * inorder_predecessor(TreeNode * node) {
        while(node->right) node = node->right;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val == key) {
            return delete_node(root);
        }

        TreeNode * temp = root;
        while(temp) {
            if(temp->val > key) {
                if(temp->left && temp->left->val == key) {
                    temp->left = delete_node(temp->left);
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                if(temp->right && temp->right->val == key) {
                    temp->right = delete_node(temp->right);
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};