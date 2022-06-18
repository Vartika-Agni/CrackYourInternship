class Solution {
public:
    void inorderTraversal(TreeNode* root) {
        
        if(root==NULL) return;
 
    /* first recur on left child */
    inorderTraversal(root->left);
 
    /* then print the data of node */
     cout<<root->val<<" ";
 
    /* now recur on right child */
    inorderTraversal(root->right);
        
    
  }
};