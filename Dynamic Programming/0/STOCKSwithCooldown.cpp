// COOLDOWN:- cannot buy right after sell
// index+1 pe buy nhi kr skte index +2 jana pdega
// buy krna fir sell krna ,, fir buy kr skte hai .. 2 lgatar buy nhi
//  do max profit
#include<bits/stdc++.h>
using namespace std;

//  TC 2^n

int solve(vector<int> &price,int n,int index,bool buy,vector<vector<int>> &dp)
{
    if(index>=n)
    {
        return 0;
    }
    if(dp[index][buy]!=-1) return dp[index][buy];
    int profit = 0;
    if(buy)
    {
        profit=max(solve(price,n,index+1,true,dp),-price[index]+solve(price,n,index+1,false,dp));
    }
    else
    {
        // CHANGED HERE
        profit=max(solve(price,n,index+1,false,dp),price[index]+solve(price,n,index+2,true,dp));
    }
    return dp[index][buy]= profit;
}
int main()
{
    vector<int> price={7,1,5,3,6,4};
    int n=price.size();
    bool buy=true;
    int index=0;
    // buy to treu ya false hoga isliye 2 lia 
    // memoisation TC =(N*2)
    // SC )(N*2)+ O(n)
    // vector<vector<int>> dp(n,vector<int> (2,-1));
    // cout<<solve(price,n,index,buy,dp);   

    // TABULATION
    // CHANGED HERE
    vector<vector<int>> dp(n+2,vector<int> (2,0));
    // for(int i=0;i<2;i++)
    // {
    // dp[n][i]=0;

    // }
    // here j=buy
    dp[n][0]=dp[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            long profit = 0;
            if(j)
            {
                profit=max(-price[i]+dp[i+1][0]  ,  0+dp[i+1][1]);
            }
            else 
            {
                profit=max(price[i]+dp[i+2][1]  ,  0+dp[i+1][0]);
            }
            

             dp[i][j]= profit;
            
        }
    }
    cout<<dp[0][1];


// SPACE OPTIMISATION NOT POSSIBLE

}