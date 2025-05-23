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
    void preOrder(vector<int>&preorder, TreeNode * root) {
        if(root == nullptr) return;
        preorder.push_back(root->val);
        preOrder(preorder,root->left);
        preOrder(preorder,root->right);
    }

    TreeNode * prev;

    void check(TreeNode * root) {
        if(root == nullptr) return ;
        check(root->right);
        check(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    void morris(TreeNode * root) {
        TreeNode * curr = root;
        while(curr) {
            if(curr->left != nullptr) {
                TreeNode * prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {
        // if(root == nullptr) return;
        // vector<int>preorder;
        // preOrder(preorder,root);
        // TreeNode * node = root;
        // for(int i = 1;i < preorder.size();i++) {
        //     node->left = nullptr;
        //     TreeNode * right_child = new TreeNode(preorder[i]);
        //     node->right = right_child;
        //     node = node->right;
        // }
        // prev = nullptr;
        // check(root);
        morris(root);
    }
};
