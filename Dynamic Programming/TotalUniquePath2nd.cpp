#include<bits/stdc++.h>
using namespace std;

// abh agr matrix mei ek dead cell bhi ho to ek base case aur add ho jaega .. ki check karo valid hai number &&a[i][j]!=-1;

// means

// if(i>=0&&j>=0&&a[i][j]!=-1){return 0;}


// int main()
// {
//     // memoisation mei
//    /* for()
//     {
//         for()
//         {
//             if(a[i][j]!=-1)dp[i][j] = 0;
//             else if(i==0&&j==0)dp[i][j] =1;
//             else {
//                 if(i>0)
//                 up=dp[i-1][j];
//                 if(j>0)left=dp[i][j-1];
//                 return left+up;
//             }

//         }
//     }
//     */
// } 

// tabulation
int mod=1e9+7;
int main()
{
    int n=3;
    int m=3;
    vector<vector<int> > v(n,vector<int>(m,1));
    v[1][1]=-1;//center vala dead cell hai bs
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==-1)dp[i][j] =0;
            else if(i==0&&j==0)dp[i][j] = 1;
            else{
                int up=0,left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    cout<<dp[2][2]<<endl;
}