#include<bits/stdc++.h>
using namespace std;


// int solve(vector<vector<int> >&v,int i,int n,int j)
// {
//     if(i==n-1)
//     {
//         return v[i][j];
//     }
//     int down=v[i][j]+solve(v,i+1,n,j);
//     int diagonal=v[i][j]+solve(v,i+1,n,j+1);

//     return min(down,diagonal);
//     // OR
//     // int diagleft=1e9;
//     // if(i>=0&&j<=n-1)
//     // {
//     //     diagleft=v[i][j]+solve(v,i+1,n,j-1);
//     // }

//     // return min(down,min(diagleft,diagonal));

// }

// memoisation
// int solve(vector<vector<int> >&v,int i,int n,int j,vector<vector<int> >&dp)
// {
//     if(i==n-1)
//     {
//         return v[i][j];
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     int down=v[i][j]+solve(v,i+1,n,j,dp);
//     int diagonal=v[i][j]+solve(v,i+1,n,j+1,dp);

//     return dp[i][j]= min(down,diagonal);
    

// }


int main()
{
    vector<vector<int>> v={{1},
                            {2,3},
                            {3,6,7},
                            {8,9,6,10}};
                            // invreasing order ,, traingle bnega
                            int row=4;
    // int ans=solve(v,0,row,0);
    // memoisation
    
    vector<vector<int> >dp(row,vector<int> (row,-1));
    // int ans=solve(v,0,row,0,dp);

    // cout<<ans<<endl;


    // TABULATION
    // for(int j=0; j<row;j++)
    // {
    //     dp[row-1][j]=v[row-1][j];
    // }
    // for(int i=row-2;i>=0;i--)
    // {
    //     for(int j=i;j>=0;j--)
    //     {
    //         int down=v[i][j]+dp[i+1][j];
    //         int diag=v[i][j]+dp[i+1][j+1];
    //         dp[i][j] =min(down,diag);
    //     }
    // }
    // cout<<dp[0][0]<<endl;


    // space opimized
    vector<int> front(row);
    for(int j=0; j<row;j++)
    {
        front[j]=v[row-1][j];
    }
    for(int i=row-2;i>=0;i--)
    {
        vector<int> curr(row);
        for(int j=i;j>=0;j--)
        {
            int down=v[i][j]+front[j];
            int diag=v[i][j]+front[j+1];
            curr[j] =min(down,diag);
        }
        front=curr;
    }
    cout<<front[0]<<endl;
}