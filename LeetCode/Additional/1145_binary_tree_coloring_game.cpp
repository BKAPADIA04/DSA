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

    TreeNode* search(TreeNode * root,int x) {
        if(root == nullptr) return nullptr;
        if(root->val == x) {
            return root;
        }

        TreeNode * left = search(root->left,x);
        TreeNode * right = search(root->right,x);
        if(left) return left;
        return right;
    }

    int countNodes(TreeNode * node) {
        if(node == nullptr) return 0;

        int left = countNodes(node->left);
        int right = countNodes(node->right);

        return left + right + 1; 
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode * node = search(root, x);
        int leftSubtree = countNodes(node->left);
        int rightSubtree = countNodes(node->right);
        int parSubtree = n - leftSubtree - rightSubtree - 1;
        // cout << leftSubtree << " " << rightSubtree << " " << parSubtree << endl;

        // left 
        int blue = leftSubtree;
        int red = n - leftSubtree;
        if(blue > red) return true;

        // right
        blue = rightSubtree;
        red = n - rightSubtree;
        if(blue > red) return true;

        // parent
        blue = parSubtree;
        red = n - parSubtree;
        if(blue > red) return true;

        return false;
    }
};
