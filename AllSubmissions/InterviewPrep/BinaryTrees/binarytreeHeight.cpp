
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
*/

/*
PURPOSE: Finds the height, of the edges between root and leaf, for a binary tree. Uses recursion.
DATE: 5-28-2019
PARAMETERS:
* Node* root, root of a binary tree, which is traversed until a leaf is found.
VARIABLES:
* int left, recursive incrementation of left node
* int right, recursive incrementation of right node
*/
    int height(Node* root) {
      if(root == NULL)
        return -1;
      else{
        int left = 1+height(root->left);
        int right = 1+height(root->right);

        return max(left, right);
      }
    }

