#include<bits/stdc++.h>
using namespace std;
// coins>=1 ye hai constraint 
int solve(vector<int> &arr,int index,int target,vector<vector<int> > &dp)
{
    
    if(index==0)
    {
        if(target%arr[0]==0) return 1;
        else
        {
            return 0;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int nottake=0+solve(arr,index-1,target,dp);
    int take=0;
    if(arr[index]<=target)
    {
        take=solve(arr,index,target-arr[index],dp);
    }
    return dp[index][target]=take+nottake;
}
int main()
{
       vector<int> arr={1,2,3};
       int target=4;
       
       

    //    TABULATION
    //    vector<vector<int> > dp(n,vector<int>(target+1,0));
    //    for(int targ=0;targ<=target;targ++)
    //    {
    //     if(targ%arr[0]==0)
    //     {
    //         dp[0][targ]=1;
    //     }
    //     else
    //     {
    //         dp[0][targ]=0;
    //     }
    //    }
    //    for(int i=1;i<n;i++)
    //    {
    //     for(int j=0;j<=target;j++)
    //     {
    //         int nottake=dp[i-1][j];
    //         int take=0;
    //         if(arr[i]<=j)
    //         {
    //             take=dp[i][j-arr[i]];
    //         }
    //          dp[i][j]=take+nottake;
    //     }
    //    }
    // cout<<dp[n-1][target]<<endl;
}