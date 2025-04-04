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

    void check(TreeNode * root, int &curr,int &answer) {
        if(root == nullptr) return;
        if(root && root->left  == nullptr && root->right == nullptr) {
            curr = curr * 10 + root->val;
            answer = answer + curr;  
            curr = curr - root->val;
            curr = curr / 10;
            return;
        }
        curr = curr * 10 + root->val;
        check(root->left,curr,answer);
        check(root->right,curr,answer);
        curr = curr - root->val;
        curr = curr / 10;
    }

    int sumNumbers(TreeNode* root) {
        int curr = 0;
        int answer = 0;
        check(root,curr,answer);
        return answer;
    }
};
