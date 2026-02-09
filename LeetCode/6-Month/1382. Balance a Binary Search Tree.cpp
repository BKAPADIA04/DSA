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

    vector<int>inorder;

    void dfs(TreeNode * root) {
        if(root == nullptr) return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    TreeNode * createBST(int low, int high) {
        if(low > high) return nullptr;

        int mid = (low + high)/2;

        TreeNode * node = new TreeNode(inorder[mid]);

        node->left = createBST(low, mid - 1);
        node->right = createBST(mid + 1, high);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        int low = 0;
        int high = inorder.size() - 1;
        TreeNode * ans = createBST(0, high);
        return ans;
    }
};
