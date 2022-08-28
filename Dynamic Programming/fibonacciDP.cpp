#include<iostream>
#include<vector>
using namespace std;

// o(n)

int f(int n,vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}
int main()
{
    int n=8;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp)<<endl;
    // tabulation
    // O(n) and O(n)
    /*
    dp[0]=0; 
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    */
    //    abh space optimised krna hai to 
    // best approach
    // array nhi bnana pda
    /*
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++)
    {
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    cout<<prev;
    */
}