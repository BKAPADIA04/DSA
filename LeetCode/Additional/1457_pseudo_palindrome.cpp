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

    void print(vector<int>&freq) {
        for(auto it:freq) cout << it << " ";
        cout << endl;
    }
    void check(TreeNode * root,int &answer,vector<int>&freq) {
        // print(freq);
        if(root == nullptr) return;

        if(root && !root->left && !root->right) {
            freq[root->val]++;
            int count = 0;
            for(int i = 1;i <= 9;i++) {
                if(freq[i] & 1) count++;
            }
            if(count <= 1) answer = answer + 1;
            freq[root->val]--;
            return;
        }

        freq[root->val]++;
        check(root->left,answer,freq);
        check(root->right,answer,freq);
        freq[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int answer = 0;
        vector<int>freq(10,0);
        // freq[root->val]++;
        check(root,answer,freq);
        return answer;
    }
};
