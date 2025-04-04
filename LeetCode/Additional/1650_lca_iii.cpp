BinaryTreeNode<int> *leastCommonAncestor(BinaryTreeNode<int> *n1, BinaryTreeNode<int> *n2)
{  
    // Write your code here.

     if (!n1 || !n2) return nullptr;

    BinaryTreeNode<int> * node1 = n1; 
    BinaryTreeNode<int> * node2 = n2;
    
    while(node1 != node2) {
        node1 = node1->parent != nullptr ? node1->parent : n2;
        node2 = node2->parent != nullptr ? node2->parent : n1;
    }

    return node1;
}
