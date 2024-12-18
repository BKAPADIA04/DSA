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
class BSTIterator {
public:

    stack<TreeNode*>s;

    BSTIterator(TreeNode* root) {
        TreeNode * curr = root;
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        if(!s.empty()) {
            TreeNode * top = s.top();
            s.pop();
            int val = top->val;
            if(top->right) {
                TreeNode * temp = top->right;
                while(temp) {
                    s.push(temp);
                    temp = temp->left;
                }
            }
        return val;
        }
        return -1;
    }
    
    bool hasNext() {
        return s.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */