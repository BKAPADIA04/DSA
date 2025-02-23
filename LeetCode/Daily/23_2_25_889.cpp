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
    TreeNode * build(vector<int>& preorder, vector<int>& postorder,int &pre_index,int &post_index) {
        if(pre_index >= preorder.size() || post_index >= postorder.size()) return nullptr;

        TreeNode * root = new TreeNode(preorder[pre_index]);
        pre_index++;
        if(root->val != postorder[post_index]) {
            root->left = build(preorder,postorder,pre_index,post_index);
        }
        if(root->val != postorder[post_index]) {
            root->right = build(preorder,postorder,pre_index,post_index);
        }
        post_index++;

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int pre_index = 0; int post_index = 0;
        return build(preorder,postorder,pre_index,post_index);
    }
    // TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    //     stack<TreeNode *>st;
    //     int pre_index = 0;
    //     int post_index = 0;

    //     TreeNode * root = new TreeNode(preorder[pre_index++]);
    //     st.push(root);

    //     while(!st.empty() && pre_index < preorder.size() && post_index < postorder.size()) {
    //         int flag = 0;
    //         while(!st.empty() && post_index < postorder.size() && st.top()->val == postorder[post_index]) {
    //             st.pop(); post_index++;flag = 1;
    //         }
    //         if(st.empty()) return root;
    //         TreeNode * node = st.top();
    //         if(flag) {
    //             node->right = new TreeNode(preorder[pre_index]);
    //             pre_index++;
    //             st.push(node->right);
    //         }
    //         else {
    //             node->left = new TreeNode(preorder[pre_index]);
    //             pre_index++;
    //             st.push(node->left);
    //         }
            // if(node->left == nullptr) {
            //     node->left = new TreeNode(preorder[pre_index]);
            //     pre_index++;
            //     st.push(node->left);
            // }
            // else {
            //     node->right = new TreeNode(preorder[pre_index]);
            //     pre_index++;
            //     st.push(node->right);
            // }
        // }

        // return root;
    // }
};
