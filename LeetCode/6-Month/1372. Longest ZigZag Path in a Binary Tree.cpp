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

    int maxi = 0;

    pair<int,int> check(TreeNode *root) {
        if(root == nullptr) return {-1,-1};

        pair<int,int>left = check(root->left);
        pair<int,int>right = check(root->right);

        int leftMove = left.second + 1;
        int rightMove = right.first + 1;

        maxi = max({maxi, leftMove, rightMove});

        return {leftMove, rightMove};
    }

    int longestZigZag(TreeNode* root) {
        if(root == nullptr) return 0;
        check(root);
        return maxi;
    }
};
