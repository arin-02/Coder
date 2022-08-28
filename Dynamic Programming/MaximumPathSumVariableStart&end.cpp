#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int> >&v,int i,int n,int j)
{
    if(i==n-1)
    {
        return v[i][j];
    }
    if(i==0)
    {
        return v[0][j];
    }
    int down=v[i][j]+solve(v,i+1,n,j);
    int diagonal=v[i][j]+solve(v,i+1,n,j+1);

    return max(down,diagonal);

   

}

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
    vector<vector<int>> v={{1,2,10,4},
                            {100,3,2,1},
                            {1,1,20,2},
                            {1,2,2,1}};
                            // invreasing order ,, traingle bnega
                            int row=4;
    int ans=solve(v,0,row,0);
    // memoisation
    
    // vector<vector<int> >dp(row,vector<int> (row,-1));
    // int ans=solve(v,0,row,0,dp);

    cout<<ans<<endl;

}