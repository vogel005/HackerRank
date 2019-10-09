

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
*/
  
  /*
  PURPOSE: Finds the lowest common ancestor between two values using recursion. 
  DATE: 5-29-2019
  PARAMETERS:
  * Node *root, begins at root of a binary tree and traverses through until it's the LCA to be returned.
  * int v1, value 1 used to traverse the tree.
  * int v2, value 2 used to traverse the tree.
  */
    Node *lca(Node *root, int v1,int v2) {
      if(v1 > root->data && v2 > root->data)
        return lca(root->right, v1, v2);
      else if(v1 < root->data && v2 < root->data)
        return lca(root->left, v1, v2);
      else // if v1 and v2 are seperate, then current node is the LCA
        return root;
    }

