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

    ll mod = 1e9 + 7;
    ll totalSum = 0;

    ll check(TreeNode * root,ll &maxi) {
        if(root == nullptr) return 0;

        ll leftSum = check(root->left,maxi);
        ll rightSum = check(root->right,maxi );

        ll sum = root->val + leftSum + rightSum;

        maxi = max(maxi,sum * (totalSum - sum));

        return sum;
    }

    int maxProduct(TreeNode* root) {
        ll maxi = 0;
        totalSum = check(root,maxi);
        check(root,maxi);
        return maxi % mod;
    }
};
