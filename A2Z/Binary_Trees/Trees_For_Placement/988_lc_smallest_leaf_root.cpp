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

    void check(TreeNode * root,string &answer,string temp) {
        if(root == nullptr) {answer = "";return;}
        char ch = root->val + 97;
        if(root->left == nullptr && root->right == nullptr) {
            // cout << temp + ch << endl;
            // string tempo = temp + ch;
            // reverse(tempo.begin(),tempo.end());

            string tempo = ch + temp;
            answer = min(answer,tempo);
        }
        if(root->left) {
            // check(root->left,answer,temp + ch);
            check(root->left,answer,ch + temp);
        }
        if(root->right) {
            check(root->right,answer,ch + temp);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        string answer(10000,'z');
        check(root,answer,"");
        cout << answer << endl;
        return answer;
    }
};