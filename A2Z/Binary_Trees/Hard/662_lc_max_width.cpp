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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        // unsigned long long max_width = 0;
        int max_width = 0;
        // queue<pair<TreeNode*,unsigned long long>>q;
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));

        while(!q.empty()) {
            int size = q.size();
            int mmin = q.front().second;
            // unsigned long long min_index = ULONG_MAX, max_index = 0;
            int min_index,max_index;
            for(int i = 0;i < size;i++) {
                TreeNode * node = q.front().first;
                // unsigned long long ind = q.front().second;
                int cur_id = q.front().second - mmin;
                q.pop();
                // min_index = min(min_index,ind);
                // max_index = max(max_index,ind);

                if(i == 0) min_index = cur_id;
                if(i == size-1) max_index = cur_id;

                max_width = max(max_width,max_index - min_index + 1);

                if(node->left) q.push(make_pair(node->left,2*cur_id+1));
                if(node->right) q.push(make_pair(node->right,2*cur_id+2));
            }
        } 
        return max_width;
    }
};