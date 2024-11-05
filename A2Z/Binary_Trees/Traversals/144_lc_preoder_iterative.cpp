vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        // preorder(root,ans);
        if(root == nullptr) return ans;

        stack<TreeNode*>s;
        s.push(root);

        while(!s.empty()) {
            TreeNode * node = s.top();
            s.pop();
            ans.push_back(node->val);

            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }