#include<iostream>
#include<vector>
using namespace std;


bool solve(vector<int> &v,int target,int index,vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(index==0) 
    {
        // return v[0]==target;
        if(target==v[0])return true;
        else{
            return false;
        }
    }
    if(dp[index][target]!=-1)return dp[index][target];
    bool nottake=solve(v,target,index-1,dp);
    bool take=false;
    if(target>=v[index])
    {
     take=solve(v,target-v[index],index-1,dp);

    }
    return dp[index][target]  =  nottake|take;
}
int main()
{
    vector<int> v={1,2,3,4};
    int target=9;
    int index=v.size();
    vector<vector<bool>> dp(index,vector<bool> (target+1,0));
    // cout<<solve(v,target,index-1,dp);
    int k=target;
    // Tabulation
   for(int i=0;i<index;i++)
   {
    dp[i][0]=true;
   }
   dp[0][v[0]]=true;
   for(int i=1;i<index;i++)
   {
    for(int j=1;j<=target;j++)
    {
        bool nottake=dp[i-1][j];
        bool take=false;
        if(v[i]<=j) take=dp[i-1][j-v[i]];
        dp[i][j]=take|nottake;
    }
   }
   cout<<dp[index-1][target]<<endl;
}