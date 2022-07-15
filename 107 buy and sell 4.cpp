class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
         int n= prices.size();
        vector<vector<int>> prev(2, vector<int>(k+1, 0));
         vector<vector<int>> curr(2, vector<int>(k+1, 0));
        
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
                for(int cap=1; cap<=k; cap++){
                    
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
        
        return prev[1][k] ;
    }
};