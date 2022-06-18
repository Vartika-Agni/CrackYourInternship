class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int subsum=0; int ans=0;
        subsum= targetSum-root->val;
        
        if(subsum==0 && root->left==NULL && root->right==NULL) return true;
        if(root->left) ans= ans||  hasPathSum(root->left,subsum);
                if(root->right) ans= ans||  hasPathSum(root->right,subsum);
        return ans;

    }
};