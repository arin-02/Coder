#include<bits/stdc++.h>
using namespace std;
// s1="bleed"
// s2="blue"
// shortest common supersequence= "bleued"


// s1="brute"
// s2="groot"
//  ans = bgruoote
// lcs 


// shortest common supersequence= s1.length()+s2.length()- LCS;

// how to print
// print from Dp table of lcs

// ####  NOT GIVING CORRECT ANSWER ######


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
    string s1="brute";
    string s2="groot";
    // vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),-1));
    // cout<<solve(s1,s2,s1.length()-1,s2.length()-1,dp)<<endl;
    // ya tabulation se poora kro
    // Tabulation
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for(int i=0;i<s1.length();i++)
    {
      dp[0][i]=0;
    }
    
    for(int i=0;i<s2.length();i++)
    {
      dp[i][0]=0;
    }
    for(int i=1;i<s1.length()+1;i++)
    {
      for(int j=1;j<=s2.length()+1;j++)
      {
        if(s1[i-1]==s2[j-1])
        {
          dp[i][j]=1+dp[i-1][j-1];
        }
        else
        {
          dp[i][j]=max(dp[i-1][j],dp[i][j-1] );
        }
      }
    }

    cout<<dp[s1.length()][s2.length()]<<endl;
    int lngth=dp[s1.length()][s2.length()];
    int i=s1.length();
    int j=s2.length();
    string s="";
    while(i>0 && j>0)
    {
      if(s1[i-1]==s2[i-1])
        {
            s+=s1[i-1];
          
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
          s+=s1[i-1];
          i--;
        }
        else
        {
          s+=s2[j-1];
          j--;
        }
    }

  while(i>0)
  {
    s+=s1[i-1];
    i--;
  }
  while(j>0)
  {
    s+=s2[j-1];
    j--;
  }
  reverse(s.begin(), s.end());
  cout<<s<<endl;


}