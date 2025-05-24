/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    // Constructor to initialize
    // the NodeValue object
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
  
    
    NodeValue largestBSTSubtreeHelper(Node* root) {
        if(root == nullptr) return NodeValue(INT_MAX,INT_MIN,0);
        
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(min(left.minNode,root->data), max(right.maxNode,root->data),left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN,INT_MAX,max(right.maxSize,left.maxSize));
    }
  
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        return largestBSTSubtreeHelper(root).maxSize;
    }
};
