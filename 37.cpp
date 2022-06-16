class Solution {
public:
    bool isSymm(TreeNode* root1, TreeNode* root2)
    {
        TreeNode *lt, *rt;
        lt=root1;
        rt= root2;
        if(rt==NULL && lt==NULL) return true;
        if(rt==NULL || lt==NULL) return false;
        
        return(lt->val==rt->val && isSymm(lt->left, rt->right) &&
               isSymm(lt->right, rt->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;
        else
           return isSymm(root->left, root->right);
        
    }
};