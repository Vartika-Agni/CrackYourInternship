#include<bits/stdc++.h>
using namespace std;

void printF(int ind,vector &ds, int arr[], int n)
{
if(ind==n){
    for(auto it:ds){
        cout<<it<<" ";
    }
    if(ds.size()==0){
        cout<<"{}";
    }
    cout<<endl;
}

//take or pick particular index into the subsequence
ds.push_back(arr[ind]);
printF(ind+1,ds,arr,n);
ds.pop_back();

//not pick conditoin ie., element not added in the subswqunce...
printF(ind+1,ds,arr,n);
}
