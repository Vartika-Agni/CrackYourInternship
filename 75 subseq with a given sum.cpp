void printS(int ind, vector<int>ds, int s, int sum, int arr[], int n){
    if(ind==n){
        if(s==sum){
            for(auto it: ds) cout<<it<<" ";
        }
        return;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];

    printS(ind+1,ds,s,sum,arr,n);
    s-=arr[i];
    ds.pop_back();

    printS(ind+1,ds,s,sum,arr,n);
}