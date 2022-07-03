class Solution {
public:
    int f(int i, int j,vector<vector<int>>& dp, vector<vector<int>>& matrix, int n)
    {
        if(j>=n || j<0) return 999999;
         if(i==0) return dp[0][j]= matrix[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
             int down=matrix[i][j]+f(i-1, j,dp, matrix,n);
             int dgr=matrix[i][j]+f(i-1, j+1,dp ,matrix,n);
             int dgl=matrix[i][j]+f(i-1, j-1,dp, matrix,n);
             return dp[i][j]= min(down, min(dgr, dgl));
    }
    
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, -1)); 
            
            int mini= 999999;
            for(int j=0; j<n; j++)
            {
                mini=min(mini,f(n-1,j,dp,matrix,n));
            }
        
         return mini;
        
    }
};