class Solution {
public:
    /**
     * Finds the lowest common ancestor (LCA) of two given nodes in a binary tree.
     * @param root The root node of the binary tree.
     * @param p The first node for which LCA is to be found.
     * @param q The second node for which LCA is to be found.
     * @return The LCA of nodes p and q.
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findLowestCommonAncestor(root, p, q);
        return ancestor;
    }

private:
    TreeNode* ancestor = nullptr; // Holds the lowest common ancestor once found

    /**
     * Helper method to perform DFS to find LCA.
     * @param current The current node being looked at.
     * @param nodeP The first node for which LCA is to be found.
     * @param nodeQ The second node for which LCA is to be found.
     * @return True if the current subtree contains either nodeP or nodeQ.
     */
    bool findLowestCommonAncestor(TreeNode* current, TreeNode* nodeP, TreeNode* nodeQ) {
        if (!current) {
            return false; // Base case: reached the end of a branch
        }

        bool left = findLowestCommonAncestor(current->left, nodeP, nodeQ); // Search LCA in the left subtree
        bool right = findLowestCommonAncestor(current->right, nodeP, nodeQ); // Search LCA in the right subtree
      
        // If both left and right are true, current is the LCA
        if (left && right) {
            ancestor = current;
        }

        // If either left or right is true and current is either nodeP or nodeQ, current is the LCA
        if ((left || right) && (current->val == nodeP->val || current->val == nodeQ->val)) {
            ancestor = current;
        }

        // Return true if current is nodeP or nodeQ or if left or right are true
        return left || right || current->val == nodeP->val || current->val == nodeQ->val;
    }
};
