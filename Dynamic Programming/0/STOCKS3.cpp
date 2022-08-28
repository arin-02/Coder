// at max 2 transaction ... limited transaction
// find max profit
#include<bits/stdc++.h>
using namespace std;



// normal
// int solve(vector<int> &price,int n,int index,bool buy,int capacity)
// {
//     if(index==n || capacity==0) 
//     {
//         return 0;
//     }
   
   
//     if(buy)
//     {
//         return max(solve(price,n,index+1,true,capacity),-price[index]+solve(price,n,index+1,false,capacity));
//     }
//     else
//     {
//         return max(solve(price,n,index+1,false,capacity),price[index]+solve(price,n,index+1,true,capacity-1));
//     }
  
// }

// memoization
int solve(vector<int> &price,int n,int index,bool buy,int capacity,vector<vector<vector<int>>> &dp)
{
    if(index==n || capacity==0) 
    {
        return 0;
    }
   
   if(dp[index][buy][capacity]!=-1) return dp[index][buy][capacity];
    if(buy)
    {
        dp[index][buy][capacity]= max(solve(price,n,index+1,true,capacity,dp),-price[index]+solve(price,n,index+1,false,capacity,dp));
    }
    else
    {
        dp[index][buy][capacity]= max(solve(price,n,index+1,false,capacity,dp),price[index]+solve(price,n,index+1,true,capacity-1,dp));
    }
    return dp[index][buy][capacity];
  
}

int main()
{
    vector<int> price={3,3,5,0,0,3,1,4};
    // profit=6;
    int n=price.size();
    int index=0;
    bool buy=true;
    // cout<<solve(price,n,index,buy,2); 
    // memoization

    // 3D
    //  vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
    // cout<<solve(price,n,index,buy,2,dp); 

    // TABULATION
     vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));

    for(int ind=0;ind<=n;ind++)
    {
        for(int buy=0;buy<2;buy++)
        {
            for(int cap=0;cap<3;cap++)
            {

            dp[ind][buy][0]=0;
            dp[n][buy][cap]=0;
            // zaroori nhi kyuki dp 0 se initialised hai
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            for(int k=2;k>=1;k--)
            {
                if(j==1)
            {
                dp[i][j][k]= max(0+dp[i+1][1][k],-price[i]+dp[i+1][0][k]);
            }
            else
            {
                dp[i][j][k]= max(0+dp[i+1][0][k],price[i]+dp[i+1][1][k-1]);
            }
            
            }
        }
    }
    cout<<dp[0][1][2];


}