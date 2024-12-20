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

    void print(vector<TreeNode*>v) {
        for(auto it:v) cout << it->val << " ";
        cout << endl;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr) return nullptr;
        bool odd = false;
        queue<TreeNode*>q;
        vector<TreeNode*>reverseNodes;
        q.push(root);
        while(!q.empty()) {
            reverseNodes.clear();
            int n = q.size();
            for(int i = 0;i < n;i++) {
                TreeNode * curr = q.front();
                q.pop();

                if(odd) reverseNodes.push_back(curr);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            // print(reverseNodes);
            if(reverseNodes.size() > 0) {
                int left = 0;
                int right = reverseNodes.size() - 1;

                while(left < right) {
                    swap(reverseNodes[left]->val,reverseNodes[right]->val);
                    left++; right--;
                }
            }
            odd = !odd;
        }
        return root;
    }
};

/*class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDFS(root->left, root->right, 0);
        return root;
    }

private:
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild == nullptr || rightChild == nullptr) {
            return;
        }
        // If the current level is odd, swap the values of the children.
        if (level % 2 == 0) {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        traverseDFS(leftChild->left, rightChild->right, level + 1);
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }
};*/