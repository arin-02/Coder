#include<bits/stdc++.h>

using namespace std;

// DO AGAIN
// NOT PRINTING CORRECT


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
    string a="abcde";
    string b="bdgek";

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
    int lngth=dp[a.length()][b.length()];
    cout<<lngth<<endl;
    string s="";
    for(int i=0;i<lngth;i++)
    {
        s+='$';
    }  
    int im=a.length();
    int jm=b.length();
    int index=lngth-1;
  while(im>0 && jm>0)
    {
        if(a[im-1]==b[jm-1])
        {
            s[index]=a[im-1];
            index--;
            im--;
            jm--;
        }
        else if(dp[im-1][jm]>dp[im][jm-1])
        {
          
            im--;
        }
        else 
        {
            jm--;
        }
    }
    cout<<s<<endl;

}