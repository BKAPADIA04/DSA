// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     map<int,TreeNode*>umap;
//     unordered_map<int,int>level;

//     void levelOrder(TreeNode * root) {
//         TreeNode * curr = root;
//         int lvl = 0;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()) {
//             int sz = q.size();
//             for(int i = 0;i < sz;i++) {
//                 TreeNode * node = q.front();
//                 q.pop();
//                 umap[node->val] = node;
//                 level[node->val] = lvl;

//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             } 
//             lvl++;
//         }
//     }

//     TreeNode * LCA(TreeNode * root, TreeNode * node1, TreeNode * node2) {
//         if(root == nullptr) return nullptr;

//         if((root->val) == (node1->val) || (root->val) == (node2->val)) return root;

//         TreeNode * left_lca = LCA(root->left,node1,node2);
//         TreeNode * right_lca = LCA(root->right,node1,node2);

//         if(left_lca && right_lca) return root;
//         if(left_lca) return left_lca;
//         return right_lca;
//     }

//     void path(TreeNode * root, TreeNode * end, string &temp, string &answer) {
//         if(root == nullptr) return;
//         if(root->val == end->val) { answer = answer + temp; return; }
        
//         temp.push_back('L');
//         path(root->left,end,temp,answer);
//         temp.pop_back();

//         temp.push_back('R');
//         path(root->right,end,temp,answer);
//         temp.pop_back();
//     }

//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         levelOrder(root);
//         TreeNode * start = umap[startValue];
//         TreeNode * end = umap[destValue];
//         TreeNode * lca = LCA(root,start,end);
//         cout << lca->val << endl;
//         string answer = string(abs(level[lca->val] - level[start->val]),'U');
//         string temp;
//         path(lca,end,temp,answer);
//         return answer;
//     }
// };

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        // Find paths from root to start and destination nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        string directions;
        int commonPathLength = 0;

        // Find the length of the common path
        while (commonPathLength < startPath.length() &&
               commonPathLength < destPath.length() &&
               startPath[commonPathLength] == destPath[commonPathLength]) {
            commonPathLength++;
        }

        // Add "U" for each step to go up from start to common ancestor
        for (int i = 0; i < startPath.length() - commonPathLength; i++) {
            directions += "U";
        }

        // Add directions from common ancestor to destination
        for (int i = commonPathLength; i < destPath.length(); i++) {
            directions += destPath[i];
        }

        return directions;
    }

private:
    bool findPath(TreeNode* node, int target, string& path) {
        if (node == nullptr) {
            return false;
        }

        if (node->val == target) {
            return true;
        }

        // Try left subtree
        path += "L";
        if (findPath(node->left, target, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path += "R";
        if (findPath(node->right, target, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
};
