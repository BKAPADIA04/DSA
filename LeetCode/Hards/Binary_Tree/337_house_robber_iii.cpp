
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

    pair<int,int>check(TreeNode * root) {
        if(root == nullptr) return {0,0};

        pair<int,int>left = check(root->left);
        pair<int,int>right = check(root->right);

        // left.first => Include Rob.
        // left.second => Exclude Rob.

        int pick = root->val + left.second +  right.second;
        int notPick = max(left.first,left.second) + max(right.first,right.second);

        return {pick,notPick};
    }

    int rob(TreeNode* root) {
        pair<int,int>ans = check(root);

        int withRoot = ans.first;
        int withoutRoot = ans.second;

        return max(withRoot,withoutRoot);
    }
};
