//Recursion--------------->

int f(int ind, int n, vector<int> &price){
    if(ind==0){
        return n*price[0];
    }
    
    int rodlength = ind+1;
    int nottake= f(ind-1, n, price);
    int take=0;
    if(rodlength<=n)
    take=price[ind] + f(ind, n-rodlength, price);
    return max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return f(n-1, n, price);
}

//memoization----------------....>
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
    if(ind==0){
        return n*price[0];
    }
    
    if(dp[ind][n]!=-1) return dp[ind][n];
    
    int rodlength = ind+1;
    int nottake= f(ind-1, n, price, dp);
    int take=0;
    if(rodlength<=n)
    take=price[ind] + f(ind, n-rodlength, price, dp);
    return  dp[ind][n] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(n-1, n, price, dp);
}

//tabulation-------------------->
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
    if(ind==0){
        return n*price[0];
    }
    
    if(dp[ind][n]!=-1) return dp[ind][n];
    
    int rodlength = ind+1;
    int nottake= f(ind-1, n, price, dp);
    int take=0;
    if(rodlength<=n)
    take=price[ind] + f(ind, n-rodlength, price, dp);
    return  dp[ind][n] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    
    for(int rs=0; rs<=n; rs++){
        dp[0][rs] = rs*price[0];
    }
    
    for(int ind=1; ind<n; ind++)
    {
        for(int rs=0; rs<=n; rs++){
            int rodlength = ind+1;
    int nottake= dp[ind-1][rs];
    int take=INT_MIN;
    if(rodlength<=rs)
    take=price[ind] + dp[ind][rs-rodlength];
    dp[ind][rs] = max(take, nottake);
        }
    }
    
    return dp[n-1][n];
}

//Space optimization--------------------------.
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> prev(n+1, -1), curr(n+1, -1);
    
    for(int rs=0; rs<=n; rs++){
        prev[rs] = rs*price[0];
    }
    
    for(int ind=1; ind<n; ind++)
    {
        for(int rs=0; rs<=n; rs++){
            int rodlength = ind+1;
    int nottake= prev[rs];
    int take=INT_MIN;
    if(rodlength<=rs)
    take=price[ind] + curr[rs-rodlength];
    curr[rs] = max(take, nottake);
        }
        prev= curr;
    }
    
    return prev[n];
}
