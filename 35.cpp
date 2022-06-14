class Solution {
public:
    bool areIdentical(TreeNode * root, TreeNode *root2)
{
    /* base cases */
    if (root == NULL && root2 == NULL)
        return true;
 
    if (root == NULL || root2 == NULL)
        return false;
 
    return (root->val == root2->val &&
            areIdentical(root->left, root2->left) &&
            areIdentical(root->right, root2->right) );
}
 

bool isSubtree(TreeNode *T, TreeNode *S)
{
    /* base cases */
    if (S == NULL)
        return true;
 
    if (T == NULL)
        return false;
 
    if (areIdentical(T, S))
        return true;

    return isSubtree(T->left, S) ||
        isSubtree(T->right, S);
}
 
};