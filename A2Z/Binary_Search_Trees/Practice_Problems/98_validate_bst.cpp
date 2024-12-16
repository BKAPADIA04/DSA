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
#define ll long long
class Solution {
public:

    void inorder(TreeNode * root,vector<int>&in) {
        if(root == nullptr) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    bool isValidBST(TreeNode* root) {
        // vector<int>in;
        // inorder(root,in);

        // for(int i = 1;i < in.size();i++) {
        //     if(in[i] <= in[i-1]) return false;
        // }
        // return true;
        if(root == nullptr || (root && root->left == nullptr && root->right == nullptr)) return true; 
        return validCheck(root,LLONG_MIN,LLONG_MAX);
    }

    bool validCheck(TreeNode * root,ll min_limit, ll max_limit) {
        if(root == nullptr) return true;

        if(root->val <= min_limit || root->val >= max_limit) {
            return false;
        }

        return validCheck(root->left,min_limit,root->val) && validCheck(root->right,root->val,max_limit);
    }
};