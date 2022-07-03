class Solution {
    bool f(int ind, int target, vector<int> &a, vector<vector<int>> &dp){
        
        if(target==0)return true;
        if(ind==0) return a[0]==target;
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        bool notTake= f(ind-1, target, a, dp);
        bool take=false;
        if(a[ind]<=target)take = f(ind-1, target-a[ind], a,dp);
        
        return dp[ind][target]=take|notTake;
    }
public:
     bool canPartition(vector<int>& a) {
        int sum=0;
        for(auto it: a)sum+=it;
        
        if(sum&1)return false;
        vector<vector<int>> dp(a.size(), vector<int> (sum/2+1, -1));
        return f(a.size()-1, sum/2, a, dp);
    }
};
   