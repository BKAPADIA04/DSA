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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,multiset<int>>>m; 
       vector<vector<int>>answer;
       if(root == nullptr) return answer;

       queue<pair<TreeNode *,pair<int,int>>>q;
       q.push(make_pair(root,make_pair(0,0)));

       while(!q.empty()) {
            TreeNode * node = q.front().first;
            int px = q.front().second.first;
            int py = q.front().second.second;
            q.pop();
            m[py][px].insert(node->val);

            if(node->left) q.push(make_pair(node->left,make_pair(px+1,py-1)));
            if(node->right) q.push(make_pair(node->right,make_pair(px+1,py+1)));
        }
        for(auto py:m) {
            vector<int>temp_ans;
            for(auto px:py.second) {
                temp_ans.insert(temp_ans.end(),px.second.begin(),px.second.end());
            }
            answer.push_back(temp_ans);
        }
        return answer;
    }
};