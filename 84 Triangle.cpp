//Memoization------------>

class Solution {
public:
    int f(int i, int j,vector<vector<int>>& triangle, int n, vector<vector<int>> &dp  )
    {
        if(i==n-1) return dp[n-1][j]=triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int d= triangle[i][j]+ f(i+1, j, triangle, n,dp);
        int dg= triangle[i][j] + f(i+1, j+1, triangle, n,dp);
        
        return dp[i][j]= min(d,dg);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(0,0,triangle,n,dp);
    }
};

//Tabulation-------------------->

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int j=0; j<n; j++) dp[n-1][j]= triangle[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; i>=0; j--)
            {
                int d=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]= min(d, dg);
            }
        }
        return dp[0][0];
    }
};

//Space optimisation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>front(n, 0), curr(n,0);
        for(int j=0; j<n; j++) front[j]= triangle[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; i>=0; j--)
            {
                int d=triangle[i][j]+front[j];
                int dg=triangle[i][j]+front[j+1];
                curr[j]= min(d, dg);
            }
            front =curr;
        }
        return front[0];
    }
};