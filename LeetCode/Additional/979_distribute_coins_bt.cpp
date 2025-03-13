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

    int check(TreeNode * root,int &answer) {
        if(root == nullptr) return 0;

        int left = check(root->left,answer);
        int right = check(root->right,answer);

        // root
        answer += abs(left) + abs(right);

        // returning statement
        return left + right + root->val - 1;
    }

    int distributeCoins(TreeNode* root) {
        int answer = 0;
        check(root,answer);
        return answer;
    }
};
