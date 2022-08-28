#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &price,int n,int index,vector<vector<int> > &dp)
{
    if(index==0) return n*price[0];

    if(dp[index][n]!=-1) return dp[index][n];

    int nottake=0+solve(price,n,index-1,dp);

    int take=-1e9;

    int rodlength=index+1;

    if(rodlength<=n) take=price[index]+solve(price,n-rodlength,index,dp);

    return dp[index][n]=max(nottake,take);
}
int main()
{
    int n=5;//rod length
    vector<int> price={2,5,7,8,10};//price of every length piece of 1 price ,, piece of 2 price....
    // vector<vector<int> > dp(n,vector<int>(n+1,-1));
    // cout<< solve(price,n,n-1,dp);
    // try to pick length & sum them up to make N aise socho...
    // knapsack jaisa bn gya
    // TABULATION
    vector<vector<int> > dp(n,vector<int>(n+1,0));

    for(int i=0;i<=n;i++)
    {
        dp[0][i]=i*price[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            int nottake=0+dp[i-1][j];

            int take=-1e9;

            int rodlength=i+1;

            if(rodlength<=j) take=price[i]+dp[i][j-rodlength];

            dp[i][j]=max(nottake,take);
        }
    }
    cout<<dp[n-1][n]<<endl;


}