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

    int i;
    vector<int>answer;
    bool check(TreeNode * root, vector<int>&voyage) {
        if(root == nullptr) return true;
        if(root->val != voyage[i++]) return false;

        if(root->left && root->left->val != voyage[i]) {
            answer.push_back(root->val);

            return check(root->right, voyage) && check(root->left, voyage);
        }

        return check(root->left, voyage) && check(root->right, voyage);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        i = 0;
        bool ans = check(root, voyage);
        if(!ans) return {-1};
        return answer;
    }
};
