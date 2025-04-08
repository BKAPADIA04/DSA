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

    pair<int,int> check(TreeNode * root, int &answer) {
        if(root == nullptr) return {0,0};

        pair<int,int> left = check(root->left,answer);
        pair<int,int> right = check(root->right,answer);

        int nodes = left.second + right.second + 1;
        int sum = left.first + right.first + root->val;
        int avg = sum/nodes;
        if(avg == root->val) answer = answer + 1;

        return {sum,nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int answer = 0;
        check(root,answer);
        return answer;
    }
};
