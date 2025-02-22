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

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int index = 0; string num = ""; int count = 0; 
        vector<int>nodes,depth;
        while(index < n) {
            while(index < n && traversal[index] != '-') {
                num += traversal[index]; index++; 
            }
            nodes.push_back(stoi(num)); depth.push_back(count);
            num = "";
            count = 0;
            while(index < n && traversal[index] == '-') {
                index++; count++;
            }
        }

        stack<pair<TreeNode*,int>>st;
        TreeNode * root = new TreeNode(nodes[0]);
        st.push({root,0}); int i = 1;
        while(!st.empty() && i < nodes.size()) {
            TreeNode * tempo = st.top().first;
            int deptho = st.top().second;

            if(depth[i] > deptho) {
                tempo->left = new TreeNode(nodes[i]);
                st.push({tempo->left,depth[i]});
                i++;
            }
            else if(depth[i] == deptho) {
                st.pop(); if(st.empty()) break;
                TreeNode * temp = st.top().first;
                temp->right = new TreeNode(nodes[i]);
                st.push({temp->right,depth[i]});
                i++;
            }
            else {
                while(!st.empty() && st.top().second >= depth[i]) st.pop();
                if(st.empty()) break;
                TreeNode * temp = st.top().first;
                temp->right = new TreeNode(nodes[i]);
                st.push({temp->right,depth[i]});
                i++;
            }
        }
        return root;
    }
};

/*class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stack;
        int index = 0;

        while (index < traversal.size()) {
            // Count the number of dashes
            int depth = 0;
            while (index < traversal.size() && traversal[index] == '-') {
                depth++;
                index++;
            }

            // Extract the node value
            int value = 0;
            while (index < traversal.size() && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            // Create the current node
            TreeNode* node = new TreeNode(value);

            // Adjust the stack to the correct depth
            while (stack.size() > depth) {
                stack.pop();
            }

            // Attach the node to the parent
            if (!stack.empty()) {
                if (stack.top()->left == nullptr) {
                    stack.top()->left = node;
                } else {
                    stack.top()->right = node;
                }
            }

            // Push the current node onto the stack
            stack.push(node);
        }

        // The root is the first node in the stack
        while (stack.size() > 1) {
            stack.pop();
        }

        return stack.top();
    }
};*/
