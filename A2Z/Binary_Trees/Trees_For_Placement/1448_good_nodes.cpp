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

    void check(TreeNode * root,int &answer,int maxi) {
        if(root == nullptr) return;
        if(root->val >= maxi) {
            answer += 1;
            maxi = root->val;
        }
        if(root->left) {
            check(root->left,answer,maxi);
        }
        if(root->right) {
            check(root->right,answer,maxi);
        }
    }

    int check1(TreeNode * root,int maxi) {
        if(root == nullptr) return 0;

        int count = 0;
        if(root->val >= maxi) {
            count++;
            maxi = max(maxi,root->val);
        }

        count += check1(root->left,maxi);
        count += check1(root->right,maxi);

        return count;
    }

    int goodNodes(TreeNode* root) {
        int answer = 0;
        // check(root,answer,INT_MIN);
        // return answer;

        return check1(root,INT_MIN);
    }
};
