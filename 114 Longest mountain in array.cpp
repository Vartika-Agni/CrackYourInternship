#include<math>
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
            vector<int>dp1(n, 1);
            vector<int>dp2(n, 1);
            vector<int>lbs(n, 0);
        
            
            //Front LIS
            for(int index = 0 ; index < n ; index++){
                for(int prev = 0 ; prev < index ; prev++){
                    if(nums[prev] < nums[index])
                        dp1[index] = max(dp1[index], 1 + dp1[prev]);
                } 
            }
            
            //Back LIS
            for(int index = n - 1 ; index >= 0 ; index--){
                for(int prev = n - 1 ; prev > index ; prev--){
                    if(nums[prev] < nums[index])
                        dp2[index] = max(dp2[index], 1 + dp2[prev]);
                } 
            }
        
            //LBS
            int res = 0;
            for(int i=0 ; i < n ; i++)
            {
                if(dp1[i] == 1 || dp2[i] == 1)
                  continue;
              res=max(res, dp1[i] + dp2[i] - 1);   
                
            }

        return n - res;
    }
};