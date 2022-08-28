// ya to k ko i se j-1 chlao aur f(i,k), f(k+1,j) krdo YA fir
// k ko i+1 se j le jao aur f(i+1,k-1),f(k,j) ye krdo 
#include<bits/stdc++.h>
using namespace std;
// O(n*n)
int solve(vector<int> &arr,int n,int i,int j,vector<vector<int>> &dp)
{
    if(i==j) return 0;
    int mini=1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j] + solve(arr,n,i,k,dp) + solve(arr,n,k+1,j,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int main()
{
    vector<int> arr={10,20,30,40,50};
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<solve(arr,n,1,n-1,dp);  

    // TABULATION
    
    
}