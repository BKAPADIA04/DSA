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

    unordered_map<int,int>freq;
    unordered_map<int,TreeNode*>rootValToNode;

    bool isValid(TreeNode * root, TreeNode * mini, TreeNode * maxi) {
        if(root == nullptr) return true;
        if(mini && root->val <= mini->val) return false;
        if(maxi && root->val >= maxi->val) return false;

        if(!root->left && !root->right && rootValToNode.count(root->val) > 0) {
            root->left = rootValToNode[root->val]->left;
            root->right = rootValToNode[root->val]->right;
            rootValToNode.erase(root->val);
        }

        return isValid(root->left, mini, root) && isValid(root->right, root, maxi);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for(auto root : trees) {
            rootValToNode[root->val] = root;
            freq[root->val]++;
            if(root->left) freq[root->left->val]++;
            if(root->right) freq[root->right->val]++;
        }

        for(auto root : trees) {
            if(freq[root->val] == 1) {
                if(isValid(root,nullptr,nullptr) && rootValToNode.size() <= 1) return root;
                return nullptr;
            }
        }
        return nullptr;
    }
};
