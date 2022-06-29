int mod= (int)(1e9 + 7);
    
    int f(int i, int j, vector<vector<int>> &dp,  vector<vector<int>> &mat)
    {
        if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=f(i-1, j,dp ,mat);
        int left=f(i, j-1, dp ,mat);
        return dp[i][j]= (up+left)% mod;
    }

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    
     vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, dp, mat);
}