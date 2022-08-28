 // ?->matches with single char
// *-> matches with sequence of length 0 or more
// string s1="?ay";
// string s2="ray";
// all matches

// string s1="ab*cd";
// string s2="abdefcd";
// all matches
// string s1="**abcd";
// string s2="abcd";
// all matches

// string s1="ab?d";
// string s2="abcc";
// return krega false;

// return true or false

#include<bits/stdc++.h>
using namespace std;

int solve(string s1,string s2,int i,int j,vector<vector<int>> &dp)
{

    if(i<0 &&j<0) return true;
    if(i<0 &&j>=0) return false;
    if(i>=0 &&j<0) 
    {
        for(int ii=0;ii<i;i++)
        {
            if(s1[ii]!='*')return false;
        }
            return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j] || s2[i]=='?')
    {
        return dp[i][j]=solve(s1,s2,i-1,j-1,dp);
    }
    if(s1[i]=='*')
    {
        return dp[i][j]=solve(s1,s2,i-1,j,dp) | solve(s1,s2,i,j-1,dp);
    }
    return dp[i][j]=false;
}
int main()
{
    string s1="ab*cd";
    string s2="abdefcd"; 
    int n=s1.length();
    int m=s2.length();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // cout<<solve(s1,s2,n,m,dp)<<endl;

    // tabulation 
    //*************** NOT DONE *************
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 &&j==0 ) dp[i][j] =true;
            if(i==0 &&j!=0) dp[i][j] =false;
            if(i!=0 &&j==0)
            {
                while(i)
                {
                    if(s1[i-1]=='*') dp[i][j] =false;
                    else
                    {
                    dp[i][j] = true;

                    }
                    i--;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1] || s2[i-1]=='?')
            {
                 dp[i][j]=dp[i-1][j-1];
            }
            if(s1[j-1]=='*')
            {
                 dp[i][j]=dp[i-1][j]|dp[i][j-1];
            }
            else{
            dp[i][j]=false;

            }
        }
    }
    cout<<dp[n][m]<<endl;
}