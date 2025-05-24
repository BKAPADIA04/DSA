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
    stack<TreeNode*>st;
    bool reverse = true;

    // reverse -> true = before
    // reverse -> false = next
public:
    BSTIterator(TreeNode * root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode * temp = st.top();
        st.pop();
        if(reverse) {
            pushAll(temp->left);
        }
        else {
            pushAll(temp->right);
        }
        int ans = temp->val;
        return ans;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode * root) {
        TreeNode * curr = root;
        while(curr) {
            st.push(curr);
            if(reverse) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
    }
};



class Solution {
public:
    // Brute Force Approach is easy -> inorder and then similar to array 2sum
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int low = l.next();
        int high = r.next();

        while(low < high) {
            int sum = low + high;
            if(sum == k) return true;
            else if(sum > k) high = r.next();
            else low = l.next();
        }
        return false;
    }
};
