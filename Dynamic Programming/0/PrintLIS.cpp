// TABULATION
#include<bits/stdc++.h>
using namespace std;



// int solve(vector<int> &arr,int n,int index,int prev_index,vector<vector<int>> &dp)
// {
//     if(index==n)
//     {
//         return 0;
//     }
    
//     if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];

//     int nottake=0+solve(arr,n,index+1,prev_index,dp);
//     int take=-1e9;
//     if(arr[prev_index]<arr[index] || prev_index==-1)
//     {
//         take=1+solve(arr,n,index+1,index,dp);
//     }
//     return dp[index][prev_index+1]=max(take,nottake);
// }
int main()
{
    vector<int> arr={10,9,2,5,3,7,101,18};
    // answer {2,3,7,101}   
    // answer {2,3,7,18}   
    // answer =length=4;
    int n=arr.size();
    // int index=0;
    // int prev_index=-1;
    // shifting of coordinate index.. kyuki prev_index=-1 hai ,, abh sbhko +1 krdo
    // prev_index ki jgah prev_index+1 krdo 



    // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    // // base case optional
    // // for(int i=0;i<=n;i++)
    // // {
    // //     dp[n][i]=0;
    // // }
    // for(int i=n-1;i>=0;i--)
    // {
        ////previndex=j iske brabr
    //     for(int j=i-1;j>=-1;j--) 
    //     {
    //         int nottake=0+dp[i+1][j+1];
    //         int take=0;
    //         if(arr[j]<arr[i] || j==-1)
    //         {
    //             take=1+dp[i+1][i+1];
    //         }
    //          dp[i][j+1]=max(take,nottake);
    //     }
    // }
    // cout<<dp[0][-1+1];

    // *******************
    // TC O(n^2)
    // SC O(n)
    // vector<int> dp(n,1);
    // int maxi=1;
    // for(int i=0;i<n;i++)
    // {
    //     for(int prev=0;prev<i;prev++)
    //     {
    //         if(arr[prev]<arr[i])
    //         {
    //             dp[i]=max(dp[i],1+dp[prev]);
    //         }
    //     }
    //     maxi=max(maxi,dp[i]);
    // }
    // cout<<maxi<<endl;


    // print the LIS
    vector<int> dp(n,1),storeindex(n);
    int maxi=1;
    int lastindex=0;
    for(int i=0;i<n;i++)
    {   storeindex[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i])
            {
                dp[i]=1+dp[prev];
                storeindex[i]=prev;
            }
        } 
        if(dp[i]>maxi)
        {
            maxi=dp[i];
            lastindex=i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastindex]);
    while(storeindex[lastindex]!=lastindex)
    {
        lastindex=storeindex[lastindex];    
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(), temp.end());
   for(auto it:temp)
   {
    cout<<it<<" ";
   }

      
}