#include<bits/stdc++.h>
using namespace std;
// constraint arr[i]>=1 ..0 nhi lena
int solver(vector<int> &arr,int target,int index,  vector<vector<int>> &dp)
{
    if(target==0) {return 1;}
    if(index==0)
     {
        return arr[0]==target;

    }
    if(dp[index][target]!=-1) return dp[index][target];
    
    int notpick=solver(arr,target,index-1,dp);
    int pick=0;
    if(arr[index]<=target) {

        pick=solver(arr,target-arr[index],index-1,dp);
        }

    return dp[index][target]=pick+notpick;


}
int main()
{
    // vector<int> arr={1,2,2,3};
    vector<int> arr={9, 7 ,0 ,3, 9, 8 ,6 ,5 ,7, 6}; //ye isliye fail ho rha hia kyukiismei 0 hai,,, isliye tabulation sahi answer dega memoization nhi 
    int n=arr.size();
    // int target=3;
    int target=31;
    
// 9 7 0 3 9 8 6 5 7 6
    vector<vector<int>> dp(n,vector<int> (target+1,-1));
    int index=n-1;
    cout<<solver(arr, target,index,dp);  


    // Tabulation
    // vector<vector<int>> dp(n,vector<int> (target+1,0));
    // for(int i=0;i<n;i++)
    // {
    //     dp[i][0]=1;
    // }
    // if(arr[0]<=target)
    // {
    // dp[0][arr[0]]=1;

    // }
    // for(int i=1;i<n;i++)
    // {
    //     for(int j=0;j<=target;j++)
    //     {
    //         int notpick=dp[i-1][j];
    //         int pick=0;
    //         if(arr[i]<=j)
    //         {
    //             pick=dp[i-1][j-arr[i]];
    //         }
    //         dp[i][j]=pick+notpick;
    //     }

    // }
    // cout<<dp[n-1][target]<<endl;
    
}