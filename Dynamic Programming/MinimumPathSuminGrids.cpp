#include<bits/stdc++.h>
using namespace std;

// 
// int minimumPathsum(vector<vector<int>>&v,int i,int j)
// {
//     if(i<0 ||j<0) return 1e9;
//     // cout<<v[i][j]<<endl;
//     if(i==0 && j==0)
//     {
//         return v[i][j];
//     }
//     int up=v[i][j]+minimumPathsum(v,i-1,j);
//     int left=v[i][j]+minimumPathsum(v,i,j-1);
//     return min(up,left);
    
// }

// memoisation
int minimumPathsum(vector<vector<int> >&v,int row,int column,int i,int j,vector<vector<int> >&dp)
{
    if(i==0&&j==0)
    {
        return v[0][0];
    }
    if(i<0 ||j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];

    int up=v[i][j]+minimumPathsum(v,row,column,i-1,j,dp);

    int left=v[i][j]+minimumPathsum(v,row,column,i,j-1,dp);

    return dp[i][j]=min(up,left);
    
}
int main()
{
    vector<vector<int>>v={{5,9,6},
                        {11,5,2}};

    // recursion

    // int n=v.size();
    // int m=v[0].size();
    
    // cout<<minimumPathsum(v,n-1,m-1);

    // memoisation
    // int row=v.size();
    // int column=v[0].size();
    // vector<vector<int> >dp(row,vector<int>(column,-1));
    
    // int ans=minimumPathsum(v,row,column,row-1,column-1,dp);
    // cout<<dp[row-1][column-1]<<endl;

    // tabulation
    int row=v.size();
    int column=v[0].size();
    vector<vector<int> > dp(row,vector<int>(column));
     dp[0][0]=v[0][0];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(i==0&&j==0){dp[i][j]=v[i][j];}
            int up=0,left=0;
            if(i>0)
            {
             up=v[i][j]+dp[i-1][j];
            }
            // else 
            // {
            //     up+=1e9;
            // }

            if(j>0)
            {
                left=v[i][j]+dp[i][j-1];
            }
            // else 
            // {
            //     left+=1e9;
            // }

            dp[i][j]=min(up,left);
        }
    }
    cout<<dp[row-1][column-1]<<endl;

    

}