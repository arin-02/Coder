// BEST time to buy and sell stocks
// vector<int> price={1,3,2,8,4,9};
// fee=2;

// buy kia 1 and sell kia 8 = 7 profit .. 7-2=5 fee minus krdi
//  fir buy kia 4 and sell kia 9 .. profit =5,,, 5-2=3 fee minus krdi .. 
//  total profit =5+3=8


// buy krna fir sell krna ,, fir buy kr skte hai .. 2 lgatar buy nhi
//  do max profit
#include<bits/stdc++.h>
using namespace std;

//  TC 2^n

int solve(vector<int> &price,int fee,int n,int index,bool buy,vector<vector<int>> &dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][buy]!=-1) return dp[index][buy];
    int profit = 0;
    if(buy)
    {
        profit=max(solve(price,fee,n,index+1,true,dp),-price[index]+solve(price,fee,n,index+1,false,dp));
    }
    else
    {
        profit=max(solve(price,fee,n,index+1,false,dp),price[index] -fee+solve(price,fee,n,index+1,true,dp));
    }
    return dp[index][buy]= profit;
}
int main()
{
    vector<int> price={1,3,2,8,4,9};
    int fee=2;
    int n=price.size();
    bool buy=true;
    int index=0;
    // buy to treu ya false hoga isliye 2 lia 
    // memoisation TC =(N*2)
    // SC )(N*2)+ O(n)
    // vector<vector<int>> dp(n,vector<int> (2,-1));
    // cout<<solve(price,fee,n,index,buy,dp);   

    // TABULATION

    // vector<vector<int>> dp(n+1,vector<int> (2,0));
    // // for(int i=0;i<2;i++)
    // // {
    // // dp[n][i]=0;

    // // }
    // // here j=buy
    // dp[n][0]=dp[n][1]=0;
    // for(int i=n-1;i>=0;i--)
    // {
    //     for(int j=1;j>=0;j--)
    //     {
    //         long profit = 0;
    //         if(j)
    //         {
    //             profit=max(-price[i]+dp[i+1][0]  ,  0+dp[i+1][1]);
    //         }
    //         else 
    //         {
    //             profit=max(price[i]-fee+dp[i+1][1]  ,  0+dp[i+1][0]);
    //         }
            

    //          dp[i][j]= profit;
            
    //     }
    // }
    // cout<<dp[0][1];


// SPACE OPTIMISATION
// vector<int> ahead(2,0),curr(2,0);

//     // for(int i=0;i<2;i++)
//     // {
//     // ahead[i]=0;

//     // }
//     // here j=buy
//     ahead[0]=ahead[1]=0;
//     for(int i=n-1;i>=0;i--)
//     {
//         for(int j=1;j>=0;j--)
//         {
//             long profit = 0;
//             if(j)
//             {
//                 profit=max(-price[i]+ahead[0]  ,  0+ahead[1]);
//             }
//             else 
//             {
//                 profit=max(price[i]-fee+ahead[1]  ,  0+ahead[0]);
//             }
            

//              curr[j]= profit;
            
//         }
//         ahead=curr;
//     }
//     cout<<ahead[1];



}