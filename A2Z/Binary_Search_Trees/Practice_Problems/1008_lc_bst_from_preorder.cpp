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

    TreeNode* Build(vector<int>&preorder,int max_limit,int &i) {
        if(i == preorder.size() || preorder[i] > max_limit) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = Build(preorder,root->val,i);
        root->right = Build(preorder,max_limit,i);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return Build(preorder,INT_MAX,i);
    }
};