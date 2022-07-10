//Recursion---------.

int f(int ind, int W, vector<int> &val, vector<int> &wt)
{
    if(ind==0){
        return ((int)(W/wt[0]))* val[0];
    }
    
    int notpick= f(ind-1, W, val, wt);
    int pick=0;
    if(wt[ind]<= W) pick= val[ind] + f(ind, W-wt[ind], val, wt);
    
    return max(pick, notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return f(n-1, w, profit, weight);
}

// Memoization---------------.
int f(int ind, int W, vector<int> &val, vector<int> &wt,  vector<vector<int>> &dp)
{
    if(ind==0){
        return ((int)(W/wt[0]))* val[0];
    }
    
    if(dp[ind][W]!=-1) return dp[ind][W];
    
    int notpick= f(ind-1, W, val, wt,dp);
    int pick=0;
    if(wt[ind]<= W) pick= val[ind] + f(ind, W-wt[ind], val, wt,dp);
    
    return dp[ind][W] = max(pick, notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, profit, weight, dp);
}

//Tabulation---------.
int f(int ind, int W, vector<int> &val, vector<int> &wt,  vector<vector<int>> &dp)
{
    if(ind==0){
        return ((int)(W/wt[0]))* val[0];
    }
    
    if(dp[ind][W]!=-1) return dp[ind][W];
    
    int notpick= f(ind-1, W, val, wt,dp);
    int pick=0;
    if(wt[ind]<= W) pick= val[ind] + f(ind, W-wt[ind], val, wt,dp);
    
    return dp[ind][W] = max(pick, notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    
    for(int i=0; i<=w; i++)
        dp[0][i] = ((int)(i/weight[0]))*profit[0];
    
    for(int ind=1; ind<n; ind++){
        for(int wt=0; wt<=w; wt++)
        {
            int notpick= dp[ind-1][wt];
    int pick=0;
    if(weight[ind] <= wt) pick= profit[ind] + dp[ind][wt-weight[ind]];
    
    dp[ind][wt] = max(pick, notpick);
        }
    }
    
    return dp[n-1][w];
}

//Space optimization--------------.

int f(int ind, int W, vector<int> &val, vector<int> &wt,  vector<vector<int>> &dp)
{
    if(ind==0){
        return ((int)(W/wt[0]))* val[0];
    }
    
    if(dp[ind][W]!=-1) return dp[ind][W];
    
    int notpick= f(ind-1, W, val, wt,dp);
    int pick=0;
    if(wt[ind]<= W) pick= val[ind] + f(ind, W-wt[ind], val, wt,dp);
    
    return dp[ind][W] = max(pick, notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
vector<int> prev(w+1, 0), curr(w+1, 0);
    
    for(int i=0; i<=w; i++)
        prev[i] = ((int)(i/weight[0]))*profit[0];
    
    for(int ind=1; ind<n; ind++){
        for(int wt=0; wt<=w; wt++)
        {
            int notpick= prev[wt];
    int pick=0;
    if(weight[ind] <= wt) pick= profit[ind] + curr[wt-weight[ind]];
    
    curr[wt] = max(pick, notpick);
        }
        prev=curr;
    }
    
    return prev[w];
}

