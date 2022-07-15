//Memoization------>
class Solution {
public:
    int f(int day, int buy, int cap,vector<int>& prices, int n,  vector<vector<vector<int>>> &dp ){
        
        if(day==n) return 0;
        if(cap==0) return 0;
        
        int profit=0;
        
        if(dp[day][buy][cap]!=-1) return dp[day][buy][cap];
        
        if(buy){
            profit = max(-prices[day] + f(day+1, 0, cap, prices, n,dp),
                        0+ f(day+1, 1, cap,prices, n,dp));
        }
        else{
            profit= max(prices[day]+ f(day+1, 1, cap-1, prices, n ,dp),
                       0+f(day+1, 0, cap, prices, n ,dp));
        }
        
        return dp[day][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, n,dp);
    }
};

//Tabulation----->
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
       //base case when day = n 
       // for(int buy=0; buy<2; buy++){
         //   for(int cap=2; cap>0; cap++){
           // dp[n][buy][cap]=0;
     //     }
       // }
         
        //base case 2 when cap=0
      //  for(int day=n-1; day>=0; day--) {
        //    for(int buy=0; buy<2; buy++)
     //           dp[day][buy][0]=0;
            //
      //  }
            
        
        for(int day=n-1; day>=0; day--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<=2; cap++){
                    
                    if(buy==1){
            dp[day][buy][cap] = max(-prices[day] + dp[day+1][0][cap], 0+ dp[day+1][1][cap]);
                       
        }
        else{
            dp[day][buy][cap] = max(prices[day]+ dp[day+1][1][cap-1] , 0+dp[day+1][0][cap]);
                                    
        }
        
                    
                }
            }
        }
        
        return dp[0][1][2] ;
    }
};
//space-----------?
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0));
         vector<vector<int>> curr(2, vector<int>(3, 0));
        
       //base case when day = n 
       // for(int buy=0; buy<2; buy++){
         //   for(int cap=2; cap>0; cap++){
           // dp[n][buy][cap]=0;
     //     }
       // }
         
        //base case 2 when cap=0
      //  for(int day=n-1; day>=0; day--) {
        //    for(int buy=0; buy<2; buy++)
     //           dp[day][buy][0]=0;
            //
      //  }
            
        
        for(int day=n-1; day>=0; day--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<=2; cap++){
                    
                    if(buy==1){
            curr[buy][cap] = max(-prices[day] + prev[0][cap], 0+ prev[1][cap]);
                       
        }
        else{
           curr[buy][cap] = max(prices[day]+ prev[1][cap-1] , 0+prev[0][cap]);
                                    
        }
        
                    
                }
            }
            prev=curr;
        }
        
        return prev[1][2] ;
    }
};