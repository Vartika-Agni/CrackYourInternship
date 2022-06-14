class Solution {
public:
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val==high && root->val==low) return root->val;
        
        if(root->val >=low && root->val<=high) 
        return root->val + rangeSumBST(root->left, low, high)+ rangeSumBST(root->right, low, high);
        
             else if (root->val < low)
         return rangeSumBST(root->right, low, high);
 
    // Else recur for left child
    else return rangeSumBST(root->left, low, high);
      }

};