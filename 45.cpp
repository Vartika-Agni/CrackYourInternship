class Solution {
public:
    bool isLeaf(TreeNode *node)
{
   if (node == NULL)
       return false;
   if (node->left == NULL && node->right == NULL)
       return true;
   return false;
}
 
    
    int sumOfLeftLeaves(TreeNode* root) {
      int res = 0;
 
    if (root != NULL)
    {
       if (isLeaf(root->left))
            res += root->left->val;
      
            res += sumOfLeftLeaves(root->left);
 
            res += sumOfLeftLeaves(root->right);
            
       }
       return res;
            
    }     
            
        };
