//Memoization---->
class Solution {
public:
    int f(int i, int prev, int n,vector<int>& nums, vector<vector<int>> dp ){
        int pick=0, notpick=0;
        
        if(i==n) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev];
        
        if(prev==-1 || nums[i]>nums[prev]) {
             pick= 1+ f(i+1, i, n, nums, dp);
        }
         notpick= 0+f(i+1, prev, n, nums, dp);
        int len= max(pick, notpick);
        
        return dp[i][prev+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1, -1));
        return f(0, -1, n, nums, dp);
        
    }
};

//tabulation------------->
int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                // not take 
                int notTake = dp[idx+1][prev+1];

                int len = notTake;
                // taking idx
                int take;
                if(prev == -1 or a[idx] > a[prev]){
                    take = 1 + dp[idx+1][idx+1];

                    len = max(take,notTake);
                } 


                dp[idx][prev+1] = len;
            }
            
        }
        return dp[0][0];
        //space-------------->
        class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        
       vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                // not take 
                int notTake = next[prev+1];

                int len = notTake;
                // taking idx
                int take;
                if(prev == -1 or a[idx] > a[prev]){
                    take = 1 + next[idx+1]; //+1 shift

                    len = max(take,notTake);
                } 


                curr[prev+1] = len; //+1 shift
            }
            next=curr;
            
        }
        return next[-1+1]; //+1 shift
        
    }
};