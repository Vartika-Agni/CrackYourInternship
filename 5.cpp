class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0 || n==1) return;
        int right=0, left=0;
        
        while(right<n)
        {
            if(nums[right]==0)
            {
                ++right;
            }
            else
            {
                int temp = nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                ++right; ++left;
            }
        }
    }
};