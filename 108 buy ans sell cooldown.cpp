//memoization--------------?
class Solution {
public:
    int f(int ind, int buy, int n, vector<int>& prices, vector<vector<int>> &dp){
        if(ind>=n) return 0;
        
        
        //for buying------>
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy==1){
            return dp[ind][buy] =  max(-prices[ind]+f(ind+1, 0,n,prices, dp),
                       0 + f(ind+1,1,n,prices,dp));
        }
        
        //for selling
        else{
            return dp[ind][buy] = max(prices[ind]+ f(ind+2, 1,n,prices,dp), 0+f(ind+1,0,n,prices,dp));           
        }
        return dp[ind][buy];
    }
    
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices, dp);
    }
};