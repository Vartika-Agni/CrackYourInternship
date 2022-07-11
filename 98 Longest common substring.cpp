class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
         int m= nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
       for(int j=0; j<=m; j++) dp[0][j]=0;

        for(int i=0; i<=n; i++) dp[i][0]=0;
        
        int ans=0;
        for(int ind1=1; ind1<=n; ind1++)
        {
            for(int ind2=1; ind2<=m; ind2++)
            {
                if(nums1[ind1-1]==nums2[ind2-1])  
                dp[ind1][ind2] =  1+ dp[ind1-1][ind2-1];
        
                else dp[ind1][ind2] =  0;
                
                ans= max(ans, dp[ind1][ind2]);
            }
        }
        
        return ans;
    }
};