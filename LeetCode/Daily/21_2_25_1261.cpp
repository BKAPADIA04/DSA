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
class FindElements {
public:

    unordered_map<int,int>m;
    void check(TreeNode * root,int value) {
        if(root == nullptr) return;

        if(root->val == -1) { root->val = value; m[value] = 1;}

        check(root->left,2*root->val+1);
        check(root->right,2*root->val+2);
    }

    FindElements(TreeNode* root) {
        check(root,0);
    }
    
    bool find(int target) {
        return m.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
