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

    void check(TreeNode * root, ll &preSum, int &targetSum, ll &answer,map<ll,ll>&m) {
        if(root == nullptr) return;

        preSum += root->val;

        if(m.find(preSum - (ll)targetSum) != m.end()) {
            answer = answer + m[preSum - targetSum];
        }

        m[preSum]++;

        check(root->left,preSum,targetSum,answer,m);
        check(root->right,preSum,targetSum,answer,m);

        m[preSum]--;
        preSum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        // if(root->left == nullptr && root->right == nullptr) return root->val == targetSum; 
        ll answer = 0;
        map<ll,ll>m; m[0] = 1; ll preSum = 0;
        check(root,preSum,targetSum,answer,m);
        return (int)answer;
    }
};
