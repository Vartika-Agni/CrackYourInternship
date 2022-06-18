class Solution {
public:
    void inorder(TreeNode* curr, int &prev, int &ans)
    {
        if(curr==NULL) return;
        
        inorder(curr->left, prev, ans);
          ans=min(abs(curr->val-prev),ans);
                prev=curr->val; 
        inorder(curr->right, prev, ans);    
    }
    
    int getMinimumDifference(TreeNode* root) {   
        
    int ans = INT_MAX;
    int  prev= INT_MAX/2;
   
    // Call in-order for the BST
    inorder(root, prev, ans);
   
    // Returning the final answer
    return ans;
    }
};