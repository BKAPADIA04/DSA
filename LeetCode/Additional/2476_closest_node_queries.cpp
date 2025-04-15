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

//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//         int n = queries.size();
//         vector<vector<int>>answer;
//         for(int i = 0;i < n;i++) {
//             int val = queries[i];
//             TreeNode * curr = root; int mini = -1; int maxi = -1;
//             while(curr) {
//                 if(curr->val == val) {
//                     mini = curr->val; maxi = curr->val;
//                     break;
//                 }
//                 else if(val > curr->val) {
//                     mini = curr->val;
//                     curr = curr->right;
//                 }
//                 else {
//                     maxi = curr->val;
//                     curr = curr->left;
//                 }
//             }
//             answer.push_back({mini,maxi});
//         }
//         return answer;
//     }
// };

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        inorder(root, ans);
        int n = ans.size();
        vector<vector<int>> s;

        for (int q : queries) {
            // Finding Floor using lower_bound
            auto it = upper_bound(ans.begin(), ans.end(), q);
            int floor = (it == ans.begin()) ? -1 : *(--it);
            if (floor > q) floor = -1;

            // Finding Ceil using upper_bound
            it = lower_bound(ans.begin(), ans.end(), q);
            int ceil = (it == ans.end()) ? -1 : *it;

            s.push_back({floor, ceil});
        }
        return s;
    }
};
