//Reciursion----------.

class Solution {
public:
    int f(int ind, int tar, vector<int>& coins)
    {
        if(ind==0)
        {
            return (tar% coins[0]==0);
        }
        
        int notpick= f(ind-1, tar, coins );
        int pick=0;
        if(coins[ind]<=tar) pick=  f(ind, tar-coins[ind], coins);
        
        return pick + notpick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return f(n-1, amount, coins);
    }
};
// memoization---------------.

class Solution {
public:
    int f(int ind, int tar, vector<int>& coins , vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            return (tar% coins[0]==0);
        }
        
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        int notpick= f(ind-1, tar, coins, dp);
        int pick=0;
        if(coins[ind]<=tar) pick=  f(ind, tar-coins[ind], coins, dp);
        
        return dp[ind][tar] = pick + notpick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return f(n-1, amount, coins, dp);
    }
};

//tabulation-------------------.
class Solution {
public:
      
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
            for(int i=0; i<=amount; i++)
                dp[0][i]= (i%coins[0]==0 );     
        
        for(int ind=1; ind<n; ind++)
        {
            for(int tar=0; tar<=amount; tar++)
            {
                int notpick= dp[ind-1][tar];
                int pick=0;
                if(coins[ind]<=tar) pick=  dp[ind][tar-coins[ind]];
        
                dp[ind][tar] = pick + notpick;
            }
        }
        
        return dp[n-1][amount];
    }
};
//space optimized-------------.

class Solution {
public:
      
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0), curr(amount+1,0);
        
        
            for(int i=0; i<=amount; i++)
                prev[i]= (i%coins[0]==0 );     
        
        for(int ind=1; ind<n; ind++)
        {
            for(int tar=0; tar<=amount; tar++)
            {
                int notpick= prev[tar];
                int pick=0;
                if(coins[ind]<=tar) pick=  curr[tar-coins[ind]];
        
                curr[tar] = pick + notpick;
            }
            prev=curr;
        }
        
        return prev[amount];
    }
};