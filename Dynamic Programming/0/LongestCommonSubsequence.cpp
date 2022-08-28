#include<bits/stdc++.h>

using namespace std;

int solve(string a,string b,int index1,int index2,vector<vector<int> >&dp)
{

    if(index1<0 ||index2<0) return 0;
    if(dp[index1][index2]!=-1 ) return dp[index1][index2];
     if(a[index1]==b[index2]) 
     {
        return 1+solve(a,b,index1-1,index2-1,dp);
     }

     return 0+max(solve(a,b,index1-1,index2,dp),solve(a,b,index1,index2-1,dp));
}
int main()
{
    string a="adebc";
    string b="dcadb";

    // answer is 3 ,,, adb
    // vector<vector<int>> dp(a.length(),vector<int>(b.length(),-1));
    // cout<<solve(a,b,a.length()-1,b.length()-1,dp)<<endl;



    // TABULATION
    // shifting of index kro .. sbh mei 
    
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
    for(int i=0;i<a.length();i++)
    {
                dp[i][0]=0;
    }
    for(int i=0;i<b.length();i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<a.length()+1;i++)
    {
        for(int j=1;j<=b.length();j++)
        {
            if(a[i]==b[j]) 
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[a.length()][b.length()]<<endl;

}