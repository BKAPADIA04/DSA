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

    int answer(TreeNode* root,int &maxi) {
        if(root == nullptr) return 0;
        int leftChildSum = max(0,answer(root->left,maxi));
        int rightChildSum = max(0,answer(root->right,maxi));

        maxi = max(maxi,leftChildSum + rightChildSum + root->val);

        return root->val + max(leftChildSum,rightChildSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        answer(root,maxi);
        return maxi;
    }
};