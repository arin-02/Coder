#include<bits/stdc++.h>
using namespace std;



int main()
{
    string s1 ="abcjklp";
    string s2 ="acjkp";
    // LCSubsequence subsequence is acjkp
    // LCSubstring substring is cjk

    

      // TABULATION
    // shifting of index kro .. sbh mei 
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for(int i=0;i<s1.length();i++)
    {
                dp[i][0]=0;
    }
    for(int i=0;i<s2.length();i++)
    {
        dp[0][i]=0;
    }
    int ans=0;
    for(int i=1;i<s1.length()+1;i++)
    {
        for(int j=1;j<=s2.length();j++)
        {
            if(s1[i]==s2[j]) 
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
                
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    cout<<ans<<endl;
    string ss="";
    int lngth=ans;
    // for(int i=0;i<lngth;i++)
    // {
    //     ss+='$';
    // }
    int im=s1.length();
    int jm=s2.length();
    
    int k=0;
    int r=0;
    for(int i=0;i<im;i++)
    {
        for(int j=0;j<jm;j++)
        {
            if(dp[i][j]==lngth)
            {
                k=i;
                r=j;
            }
        }
    }
    while(k>0 && r>0)
    {
        ss+=s1[k];
        k--;
        r--;
    }
    reverse(ss.begin(),ss.end());
    cout<<ss<<endl;
        
    
    

}