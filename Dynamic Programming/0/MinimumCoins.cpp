// repeated coins le skte hai 
// find minimum number of coins...
#include<bits/stdc++.h>
using namespace std;
// TC eponential 
// SC o(target)
int solve (vector<int> &arr,int target,int index,vector<vector<int> > &dp)
{
    if(target==0) return 0;
    if(index==0 )
    {
        if(target%arr[index]==0) return target/arr[index];
        else{
            return 1e9;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int nottake=0+solve(arr,target,index-1,dp);
    int take=1e9;
    if(arr[index]<=target)
    {
    take=1+solve(arr,target-arr[index],index,dp);
    // isme doosra case lene ki zaroorat nhi take vaale mei 
    // 1+solve(arr,target-arr[index],index-1)
    // ye vaala kyuki arr[index]<=target unsatisfy hoga fir vo pichle pe chla jaega

    }
   
    return dp[index][target]=min(nottake,take);

}
int main()
{
    vector<int> arr={1,2,3};
    int target=7;
    int n=arr.size();
    // vector<vector<int> > dp(n,vector<int>(target+1,-1));
    // cout<<solve(arr,target,n-1,dp);
    
    // TABULATION

    vector<vector<int> > dp(n,vector<int>(target+1,0));
    for(int targ=0;targ<=target;targ++)
    {
        if(targ%arr[0]==0) dp[0][targ]=targ/arr[0];
        else
        {
            dp[0][targ]=1e9;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            
            int nottake=0+dp[i-1][j];
            int take=1e9;
            if(arr[i]<=j)
            {
            take=1+dp[i][j-arr[i]];
            
            }
            dp[i][j]=min(take,nottake);
        }
    }
    cout<<dp[n-1][target]<<endl;

}