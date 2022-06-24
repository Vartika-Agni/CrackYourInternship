class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int N){
        int buy=0,sell=0,flag=0;
        vector<vector<int> > ans;
        for(int i=1;i<N;i++){
            if(A[i] >= A[i-1] && A[i] != A[buy]){
                sell++;
                flag = 1;
            }
            else if(buy == sell){
                buy = i;
                sell = i;
            }
            else{
                vector<int> vec;
                vec.push_back(buy);
                vec.push_back(sell);
                ans.push_back(vec);

                buy = i;
                sell = i;
            }
        }
        if(flag == 0)
            return ans;
            //ye isliye ki agar i out of bound ho jae sell++ ki wajahs e aur loop k bahar aa aje to usko end me
           // enter krle
        else if(buy != N-1 && sell == N-1){
            vector<int> temp;
            temp.push_back(buy);
            temp.push_back(sell);
            ans.push_back(temp);
        }
        return ans;
        
    }
    
};