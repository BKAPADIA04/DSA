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
    TreeNode * build(map<int,int>&m, vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if((preStart > preEnd) || (inStart > inEnd)) return nullptr;

        TreeNode * root = new TreeNode(preorder[preStart]);

        int inorder_posn = m[root->val];
        int left_tree_size = inorder_posn - inStart;

        root->left = build(m,preorder,preStart+1,preStart + left_tree_size, inorder, inStart, inorder_posn - 1);
        root->right = build(m,preorder,preStart + left_tree_size + 1,preEnd, inorder, inorder_posn+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i = 0;i < inorder.size();i++) {
            m[inorder[i]] = i;
        }
        TreeNode * root = build(m,preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);

        return root;
    }
};