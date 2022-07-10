//Memoization------------------.
class Solution {
public:
    int f(int ind, int tar,vector<int>& coins , vector<vector<int>> &dp)
    { 
         if(ind==0)
        {
            if(tar % coins[0]==0) return tar/coins[0];
     
            return 1e9;
        }
        
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        int notpick=f(ind-1, tar, coins,dp);
        int pick= 1e9;
        if(coins[ind]<=tar)
        pick= 1 + f(ind, tar-coins[ind], coins,dp);
        
        return dp[ind][tar]=  min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=0;
        n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans= f(n-1, amount, coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};

//tabulation---------------.
int coinChange(vector<int>& coins, int amount) {
        int n=0;
        n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        
    
        for(int t=0; t<=amount; t++)
           if(t%coins[0]==0) dp[0][t]=t/coins[0];
           else dp[0][t]=1e9;
        
        for(int ind=1; ind<n; ind++)
        {
            for(int tar=0; tar<=amount; tar++)
            {
                 int notpick=dp[ind-1][tar];
                 int pick= 1e9;
                 if(coins[ind]<=tar)
                 pick= 1 + dp[ind][tar-coins[ind]];
        
                 dp[ind][tar]=  min(pick, notpick);
            }
        }
       if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
    }

    //space optimization------------------>
    class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {
        int n=0;
        n=coins.size();
        vector<int>prev(amount+1, 0), curr(amount+1, 0);
        
    
        for(int t=0; t<=amount; t++)
           if(t%coins[0]==0) prev[t]=t/coins[0];
           else prev[t]=1e9;
        
        for(int ind=1; ind<n; ind++)
        {
            for(int tar=0; tar<=amount; tar++)
            {
                 int notpick= prev[tar];
                 int pick= 1e9;
                 if(coins[ind]<=tar)
                 pick= 1 + curr[tar-coins[ind]];
        
                 curr[tar]=  min(pick, notpick);
            }
            prev=curr;
        }
        int ans= prev[amount];
       if(ans>=1e9) return -1;
        return ans;
    }
};