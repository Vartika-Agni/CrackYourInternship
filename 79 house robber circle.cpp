long long int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
   int prev=nums[0];
    int prev2=0;
   for(int i=1;i<n;i++)
   {
       int take=nums[i];
       if(i>1) take+=prev2;
        int notake=0+prev;
       
       int curr=max(take, notake);
       
       prev2=prev;
      prev=curr;
   }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int>temp1, temp2;
        int n=valueInHouse.size();
        if(n==1) return valueInHouse[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(valueInHouse[i]);
            if(i!=n-1) temp2.push_back(valueInHouse[i]);
        }
        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}