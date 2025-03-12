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

    TreeNode * build(TreeNode * root,int sum,int limit) {
        if(root == nullptr) return nullptr;
        
        sum += root->val;

        if(!root->left && !root->right) {
            if(sum < limit) return nullptr;
            return root;
        }

        root->left = build(root->left,sum,limit);
        root->right = build(root->right,sum,limit);

        if(root->left == nullptr && root->right == nullptr) return nullptr;
        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return build(root,0,limit);
    }
};
