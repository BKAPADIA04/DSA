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

    int answer;

    int dfs(TreeNode* root, int start) {
        if(root == nullptr) return 0;

        int leftDepth = dfs(root->left, start);
        int rightDepth = dfs(root->right, start);

        if(root->val == start) {
            answer = max(leftDepth, rightDepth);
            return -1;
        }

        if(leftDepth >= 0 && rightDepth >= 0) {
            return max(leftDepth,rightDepth) + 1;
        }

        int dist = abs(leftDepth) + abs(rightDepth);
        answer = max(answer, dist);
        return min(leftDepth, rightDepth) - 1;
    }

    int amountOfTime(TreeNode* root, int start) {
        answer = 0;
        dfs(root, start);
        return answer;
    }
};
