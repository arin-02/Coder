// insert ,remove, replace can be used ,,, phele sirf insert and remove use kia tha
#include<bits/stdc++.h>
using namespace std;

int solve(string s1,string s2,int n,int m,int i,int j,vector<vector<int>> &dp)
{
    if(i<0)
    {
        return j+1;
    }
    if(j<0)
    {
        return i+1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j])
    {
        return 0+solve(s1,s2,n,m,i-1,j-1,dp);
    }
    
        int a=1+solve(s1,s2,n,m,i,j-1,dp);//insert
        int b=1+solve(s1,s2,n,m,i-1,j,dp);//deletion
        int c=1+solve(s1,s2,n,m,i-1,j-1,dp);//replace
        return dp[i][j]=min(a,min(b,c));

    
}
int main()
{
    string s1="horse";
    string s2="ros";
    // rorse,,,,rose,,,ros
    // string s1="intention";
    // string s2="execution";
    // vector<vector<int>> dp (s1.length(),vector<int>(s2.length() ,-1));
    // cout<<solve(s1,s2,s1.length(),s2.length(),s1.length()-1,s2.length()-1,dp)<<endl;  

    // tabulation

    vector<vector<int>> dp (s1.length()+1,vector<int>(s2.length()+1 ,0));

    for(int i=0;i<s1.length();i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<s2.length();i++)
    {
        dp[0][i]=i;
    }
     
     for(int i=1;i<s1.length()+1;i++)
     {
        for(int j=1;j<=s2.length();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]= 0+dp[i-1][j-1];
            }
            
            else{

                int a=1+dp[i][j-1];//insert
                int b=1+dp[i-1][j];//deletion
                int c=1+dp[i-1][j-1];//replace
                 dp[i][j]=min(a,min(b,c));
            }
        }
     }
     cout<<dp[s1.length()][s2.length()]<<endl;
}