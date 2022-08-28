#include<bits/stdc++.h>
// count ways
using namespace std;

int solve(string s1, string s2, int index1,int index2,vector<vector<int>> &dp)
{
    // ###### 1 based indexing ##########
    // index1=s1.length();
    // index2=s2.length(); aise passkro
    // if(index2==0) return 1;
    // if(index1==0) return 0;
    // if(dp[index1][index2]!=-1) return dp[index1][index2];
    // // index2 vala index1 mei nhi lia 
    // if(s1[index1-1]==s2[index2-1]) //0 based indexing hai isliye aisa likha 
    // {
    // return dp[index1][index2]=solve(s1, s2, index1-1, index2-1,dp)+ solve(s1, s2, index1-1, index2,dp);

    // }

    // return dp[index1][index2]=solve(s1,s2,index1-1,index2,dp);


    // ***** 0 based indexing *******
    if(index2<0) return 1;
    if(index1<0) return 0;
    if(dp[index1][index2]!=-1) return dp[index1][index2];
    // index2 vala index1 mei nhi lia 
    if(s1[index1]==s2[index2]) //0 based indexing hai isliye aisa likha 
    {
    return dp[index1][index2]=solve(s1, s2, index1-1, index2-1,dp)+ solve(s1, s2, index1-1, index2,dp);

    }

    return dp[index1][index2]=solve(s1,s2,index1-1,index2,dp);
 
}
int main()
{
    string s1="babgbag";
    string s2="bag";
    // string s1="rabbbit";
    // string s2="rabbit";
    //number of times s2 occur in s1

    // mormal
    // cout<<solve(s1,s2,s1.length(),s2.length())<<endl; 
    // memoization

    // vector<vector<int>> dp(s1.length(),vector<int> (s2.length(),-1));
    // cout<<solve(s1,s2,s1.length()-1,s2.length()-1,dp)<<endl; 

    // tabulation
    vector<vector<int>> dp(s1.length()+1,vector<int> (s2.length()+1,0));
    // 1 base indexing bnao +1 krdo base case tha ajeeb isliye
    for(int i=0;i<=s1.length();i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=s2.length();i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<s1.length()+1;i++)
    {
        for(int j=1;j<=s2.length();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
             dp[i][j]=dp[i-1][j-1]+ dp[i-1][j];

            }
            else
            {
             dp[i][j]=dp[i-1][j];

            }
        }
    }
    cout<<dp[s1.length()][s2.length()]<<endl;
}