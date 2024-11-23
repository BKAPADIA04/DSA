vector<int>MorrisPreorder(TreeNode * root) {
        vector<int>answer;
        if(root == nullptr) return answer;

        TreeNode * curr = root;
        while(curr) {
            if(curr->left == nullptr) {
                answer.push_back(curr->val);
                curr = curr -> right;
            }
            else {
                TreeNode * prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == nullptr) {
                    prev->right = curr;
                    answer.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return answer;
    }