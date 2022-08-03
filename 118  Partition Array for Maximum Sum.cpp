class Solution {
public:
    int f(int i,int n, vector<int>& arr, int k, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int maxAns=0, len=0, maxi= INT_MIN;
        
        for(int j=i; j<min(n, i+k); j++){
            len++;
            maxi= max(maxi, arr[j]);
           int sum= len*maxi + f(j+1,n ,arr,k, dp);
            maxAns= max(sum, maxAns);
        }
        return dp[i] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n+1, -1);
        return f(0,n,arr,k,dp);
    }
};