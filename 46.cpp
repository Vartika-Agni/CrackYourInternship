class Solution {
public:
    
    int calcheight(TreeNode *root)
    {
        if(root==NULL) return 0;
        
        int lheight=calcheight(root->left);
        int rheight=calcheight(root->right);
        return max(lheight, rheight)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        int lh; /* for height of left subtree */
        int rh; /* for height of right subtree */
 
    /* If tree is empty then return true */
    if (root == NULL)
        return 1;
 
    /* Get the height of left and right sub trees */
    lh = calcheight(root->left);
    rh = calcheight(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
 
    /* If we reach here then
    tree is not height-balanced */
    return 0;
    }
};