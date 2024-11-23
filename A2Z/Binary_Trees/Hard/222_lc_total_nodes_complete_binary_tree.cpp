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

    void answer(TreeNode * root,int &ans) {
        if(root == nullptr) return;

        if(root) {
            ans += 1;
        }

        answer(root->left,ans);
        answer(root->right,ans);
    }

    int left_height(TreeNode * root) {
        if(root == nullptr) return 0;
        int answer = 0;
        while(root) {
            answer++;
            root = root->left;
        }
        return answer;
    }

    int right_height(TreeNode * root) {
        if(root == nullptr) return 0;
        int answer = 0;
        while(root) {
            answer++;
            root = root->right;
        }
        return answer;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = left_height(root);
        int rh = right_height(root);

        if(lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};