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

    int height(TreeNode * node) {
        if(node == nullptr) return 0;

        return 1 + max(height(node->left),height(node->right));
    } 

    int height_check(TreeNode * root,int &answer) {
        if(root == nullptr) return 0;
        
        int lh = height_check(root->left,answer);
        int rh = height_check(root->right,answer);

        answer = max(answer,lh+rh);

        return 1 + max(lh,rh);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        // int dia = height(root->left) -1 + height(root->right) -1 + 2;
        int answer = 0;
        height_check(root,answer);
        return answer;
        // return max(dia,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};