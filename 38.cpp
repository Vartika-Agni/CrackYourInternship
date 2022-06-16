class Solution {
public:
    void preOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
    TreeNode* sortedArray(vector<int> nums,
                        int start, int end)
{
   
    if (start > end)  return NULL;
    int mid = (start + end)/2;
    TreeNode* root = new TreeNode(nums[mid]);
 
    root->left = sortedArray(nums, start, mid - 1);
    root->right = sortedArray(nums, mid + 1, end);
 
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return sortedArray(nums,0,n-1);
        
        
        
    }
};