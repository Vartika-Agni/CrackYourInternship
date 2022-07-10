class Solution {
public:
    
    int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
        if(num[0]!=0 && num[0]<=tar) dp[0][num[0]]=1;
        for(int ind=1; ind<n; ind++)
        {
            for(int sum=0; sum<=tar; sum++)
            {
    int nottake=dp[ind-1][sum];
    int take=0;
    if(num[ind]<=sum) take=dp[ind-1][sum-num[ind]];
    
     dp[ind][sum]=  (take+nottake);
            }
        }
         
    return dp[n-1][tar];
   
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(auto &it: arr) totsum+=it;
    if ((totsum-d)%2 || (totsum-d)<0) return false;
    int tar= (totsum-d)/2;
    return findWays(arr,tar);
}

    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return countPartitions(n, target, nums);
    }
};