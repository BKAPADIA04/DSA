/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // void height(TreeNode * root, TreeNode * target, int k,int &answer) {
    //     if(root == nullptr) return;
    //     if(root == target) {
    //         answer = k; return;
    //     }

    //     height(root->left,target,k+1,answer);
    //     height(root->right,target,k+1,answer);
    // }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == nullptr) return {};
        map<TreeNode*,TreeNode*>m;
        queue<pair<TreeNode*,int>>q; q.push({root,0});
        // m[root] = nullptr;
        while(!q.empty()) {
            TreeNode * node = q.front().first;
            q.pop();
            if(node->left) {
                q.push({node->left,0}); m[node->left] = node;
            }
            if(node->right) {
                q.push({node->right,0}); m[node->right] = node;
            }
        }

        vector<int>answer;
        q.push({target,0});
        unordered_set<TreeNode*>visited;
        visited.insert(target);
        while(!q.empty()) {
            TreeNode * node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist == k) {
                answer.push_back(node->val);
                continue;
            }
            if(node->left && visited.find(node->left) == visited.end()) {
                q.push({node->left,dist+1}); 
                visited.insert(node->left);
            }
            if(node->right && visited.find(node->right) == visited.end()) {
                q.push({node->right,dist+1}); 
                visited.insert(node->right);
            }
            if(m.find(node) != m.end() && visited.find(m[node]) == visited.end()) {
                q.push({m[node],dist+1}); 
                visited.insert(m[node]);
            }
        }

        return answer;
    }
};