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

    void check(TreeNode * root, int &maxi, int &mini,int &answer) {
        if(root == nullptr) return;
        answer = max({answer,abs(root->val - maxi),abs(root->val - mini)});
        int temp_max = maxi; int temp_min = mini;
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        check(root->left,maxi,mini,answer);
        check(root->right,maxi,mini,answer);
        maxi = temp_max;
        mini = temp_min;
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        int answer = 0;
        int maxi = root->val; int mini = root->val;
        check(root,maxi,mini,answer);
        return answer;
    }
};
