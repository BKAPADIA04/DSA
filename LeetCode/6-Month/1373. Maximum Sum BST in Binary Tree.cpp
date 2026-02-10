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

    ll ans;
    // {isBST, sum, maxi, mini}

    vector<ll>dfs(TreeNode *root) {
        if(root == nullptr) return {1ll, 0ll,LLONG_MIN, LLONG_MAX};

        vector<ll>leftChild = dfs(root->left);
        vector<ll>rightChild = dfs(root->right);

        if(leftChild[0] == 1ll && rightChild[0] == 1ll && root->val > leftChild[2] && root->val < rightChild[3]) {
            ll sum = leftChild[1] + (ll)root->val + rightChild[1];
            ans = max(ans, sum);
            ll currMin = min(leftChild[3], (ll)root->val);
            ll currMax = max(rightChild[2], (ll)root->val);

            return {1ll,sum,currMax,currMin};
        }

        return {0ll,0ll,0ll,0ll};
    }

    int maxSumBST(TreeNode* root) {
        ans = LLONG_MIN;
        dfs(root);
        if(ans < 0ll) ans = 0ll;
        return ans;
    }
};
