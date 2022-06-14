class Solution {
public:
    int calcheight(TreeNode *root)
    {
        if(root==NULL) return 0;
        
        int lheight=calcheight(root->left);
        int rheight=calcheight(root->right);
        return max(lheight, rheight)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
               if(root==NULL) return 0;
        int lh= calcheight(root->left);
        int rh= calcheight(root->right);
        int currdia=lh+rh;
        
        int ldia= diameterOfBinaryTree(root->left);
        int rdia= diameterOfBinaryTree(root->right);

        return max(currdia, max(ldia, rdia));

    }
};