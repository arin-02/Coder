#include<iostream>
using namespace std;

// recursion
// 2^n*m TC
// SC O((N-1)+(M-1))
// int solve(int arr[][3],int i,int j,int destx,int desty)
// {
//     if(i<0||j<0)
//     {
//         return  0;
//     }
//     if(i==0&&j==0)
//     { 
//         return 1;
//     }
//     int up=solve(arr,i-1,j,destx,desty);
//     int left=solve(arr,i,j-1,destx,desty);
//     return left+up;
// }
// memoisation
// TC N*M
// SC O(N-1)+M-1) +O(N*M)->dp
// int solve(int arr[][3],int i,int j,int destx,int desty,int dp[][3])
// {
//     if(i<0||j<0)
//     {
//         return  0;
//     }
//     if(i==0&&j==0)
//     { 
//         return dp[0][0]=1;
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     int up=solve(arr,i-1,j,destx,desty,dp);
//     int left=solve(arr,i,j-1,destx,desty,dp);
//     return dp[i][j]=left+up;
// }

// tabulation
// TC and SC = O(N*M)
int solve(int arr[][3],int i,int j,int destx,int desty,int dp[][3])
{
    dp[0][0] =1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==0&&j==0)
            {
                dp[0][0]=1;
            }
            else
            {
                int up=0,left=0;

                if(i>0)
                {
                 up=dp[i-1][j];
                }
                if(j>0)
                {

                 left=dp[i][j-1];
                }

                dp[i][j]=up+left; 
            }
        }
    }
    return dp[2][2];
}
int main()
{
    int arr[3][3];
    int m=3,n=3;
    int dp[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][j]=-1;
        }
    }
    // dp bnao m aur n leke
    int ans=solve(arr,m-1,n-1,0,0,dp);
    cout<<ans<<endl;

}