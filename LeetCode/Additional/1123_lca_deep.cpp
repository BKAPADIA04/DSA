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

    pair<TreeNode*,int> lca(TreeNode * root) {
        if(root == nullptr) return { nullptr, 0 };
        pair<TreeNode *,int > left = lca(root->left);
        pair<TreeNode *,int > right = lca(root->right);

        if(left.second > right.second) return {left.first,left.second + 1};
        if(right.second > left.second) return {right.first,right.second + 1};
        return {root,left.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<TreeNode *,int > ans = lca(root);
        return ans.first;
    }
};
