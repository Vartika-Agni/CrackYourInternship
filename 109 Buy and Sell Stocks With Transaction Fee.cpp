//memoization------?>
class Solution {
public:
    int f(int ind, int buy, int n, vector<int>& prices, vector<vector<int>> &dp,int &fee){
        if(ind==n) return 0;
        
        int profit=0;
        //for buying------>
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy){
            profit=max(-prices[ind]+f(ind+1, 0,n,prices, dp,fee)-fee,
                       0 + f(ind+1,1,n,prices,dp, fee));
        }
        
        //for selling
        else{
            profit= max(prices[ind]+ f(ind+1, 1,n,prices,dp,fee), 0+f(ind+1,0,n,prices,dp,fee));           
        }
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices,dp, fee);
    }
};

