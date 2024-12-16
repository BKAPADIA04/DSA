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

    void kth_small(TreeNode * root, int &counter, int k,int &answer) {
        if(root == nullptr || counter >= k) return;

        kth_small(root->left,counter,k,answer);
        counter++;
        if(counter == k) {
            answer = root->val;
            return;
        }
        // cout << counter << endl;
        kth_small(root->right,counter,k,answer);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        TreeNode * temp = root;
        int answer = 0; int counter = 0;
        kth_small(root,counter,k,answer);
        return answer;
    }
};