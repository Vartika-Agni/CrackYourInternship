class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        
        int prev2=0, prev=1, curr=0;
        
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};