class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
    {
        TreeNode *lt, *rt;
        lt=root1;
        rt= root2;
        if(rt==NULL && lt==NULL) return true;
        if(rt==NULL || lt==NULL) return false;
        
        return(lt->val==rt->val && isSameTree(lt->left, rt->left) &&
               isSameTree(lt->right, rt->right));
    }
    }
};