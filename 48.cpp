class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int i = 0;
        int end = nums.size()-1;
        int temp;
        while(i<=end){
            if(nums[i]==2){
                temp = nums[end];
                nums[end] = nums[i];
                nums[i] = temp;
                end--;
            } else if(nums[i]==1){
                i++;
            } else if(nums[i]==0){
                temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;
                start++;
                i++;
            }
        }
    }
};