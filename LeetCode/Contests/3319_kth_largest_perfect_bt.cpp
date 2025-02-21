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
//     int count(TreeNode * root) {
//         if(root == nullptr) return 0;
//         return 1 + count(root->left) + count(root->right);
//     }

//     int check(TreeNode * root,vector<int>&answer) {
//         if(root == nullptr) return 0;
//         // int leftHeight = 0; int rightHeight = 0;
//         int leftHeight = 1 + check(root->left,answer);
//         int rightHeight = 1 + check(root->right,answer);

//         if(leftHeight == rightHeight && (count(root) == (pow(2,leftHeight)-1))) {
//             answer.push_back(count(root));
//         }
        
//         return max(leftHeight,rightHeight); 
//     }

//     int kthLargestPerfectSubtree(TreeNode* root, int k) {
//         vector<int>answer = {};
//         check(root,answer);
//         sort(answer.begin(),answer.end(),greater<int>());
//         // for(auto it:answer) cout << it << " ";
//         if(answer.size() < k) return -1;
//         return answer[k-1];
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> a;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == -1 || right == -1 || left != right)
            return -1;
        a.push_back(left + 1);
        return left + 1;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(a.begin(), a.end(), greater<int>());
        if (a.size() < k)
            return -1;
        return (1 << a[k - 1]) - 1;
    }
};
