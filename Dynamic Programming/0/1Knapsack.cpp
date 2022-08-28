#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &wt,vector<int> &val,int bag,int index,vector<vector<int> > &dp)
// {
//     if(bag==0)return 0;
//     if(index==0) 
//     {
//         if(wt[index]<=bag)return val[index];
//         else 
//         {
//             return 0;
//         }
//     }
//     if(dp[index][bag]!=-1) return dp[index][bag];
//     int notpick=0+solve(wt,val,bag,index-1,dp);
//     int pick=-1e9;
//     if(wt[index]<=bag)
//     {
//      pick=val[index]+solve(wt,val,bag-wt[index],index-1,dp);

//     }
//     return dp[index][bag]=max(notpick,pick);
// }
int main()
{
    vector<int> wt={3,4,5};
    vector<int> val={30,50,60};
    int n=3;
    int bag=8;
    int index=n-1;
    // vector<vector<int> > dp(n,vector<int>(bag+1,-1));
    // cout<<solve(wt,val,bag,index,dp)<<endl;

    // TABULATION
    vector<vector<int> > dp(n,vector<int>(bag+1,0));
    for(int i=wt[0];i<bag;i++)
    {
        dp[0][i]=val[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=bag;j++)
        {
            int nottake=0+dp[i-1][j];
            int take=-1e9;
            if(wt[i]<=j)
            {
                take=val[i]+dp[i-1][j-wt[i]];
            }
            dp[i][j]=max(take,nottake);
        }
    }
    cout<<dp[n-1][bag]<<endl;

    

}