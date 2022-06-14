class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
 { 
	if (root == NULL) 
		return root; 
	else
	{ 
		TreeNode* temp; 
		
		/* recursive calls */
		invertTree(root->left); 
		invertTree(root->right); 
	
		/* swap the pointers in this root */
		temp	 = root->left; 
		root->left = root->right; 
		root->right = temp; 
	} 
        return root;
 } 
};
