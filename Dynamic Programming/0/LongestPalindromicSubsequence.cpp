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
    string s ="bbbab";
    string t=s;
   reverse(t.begin(),t.end());
   vector<vector<int> >dp(s.length(),vector<int>(t.length(),-1));
   cout<<solve(s,t,s.length()-1,t.length()-1,dp);
        
}