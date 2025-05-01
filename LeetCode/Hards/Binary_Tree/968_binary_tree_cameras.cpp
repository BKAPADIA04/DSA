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

    int check(TreeNode * root,int &answer) {
        if(root == nullptr) return 1;

        int left = check(root->left, answer);
        int right = check(root->right, answer);

        if(left == 0 || right == 0) {
            answer += 1;
            return 2;
        }

        if(left == 1 && right == 1) {
            return 0;
        }

        if(left == 2 || right == 2) {
            return 1;
        }

        return -1;
    }


    int minCameraCover(TreeNode* root) {
        // 0 -> no camera, not monitored
        // 1 -> no camera, monitored
        // 2 -> camera

        int answer = 0;
        if(check(root,answer) == 0) answer += 1; // root is not monitored
        return answer;
    }
};
