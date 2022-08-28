#include<iostream>
#include<vector>

using namespace std;

// int MaxSumOfNonAdjacent(vector<int> v,int index)
// {
//     if(index == 0) return v[index];
//     if(index<0) return 0;
//     int pick=v[index]+ MaxSumOfNonAdjacent(v,index-2); 
//     int notpick=0+MaxSumOfNonAdjacent(v,index-1);
   
//     return max(pick,notpick);
// }

// memoization


// int MaxSumOfNonAdjacent(vector<int> v,int index,vector<int>&dp)
// {
//     if(index == 0) return v[index];
//     if(index<0) return 0;
//     if(dp[index]!=-1)return dp[index];
//     int pick=v[index]+ MaxSumOfNonAdjacent(v,index-2,dp);
//     int notpick=0+MaxSumOfNonAdjacent(v,index-1,dp);
   
//      return dp[index]=max(pick,notpick);
     
// }


// tabulation
// -------------------NOT CONFIRM-------------------
// int MaxSumOfNonAdjacent(vector<int> v,int index,vector<int>&dp)
// {
//     dp[0]=v[0];
//     int neg=0;
//     int i;
//     for( i=1;i<v.size();i++)
//     {
//         int take=v[index];
//         if(i>1)take+=dp[i-2];
//     //    if(i==1) take+=0;
//         int nontake=0+dp[i-1];
//         dp[i]=max(take,nontake);
//     }
//     return dp[v.size()-2];
     
// }

// space optimized
int MaxSumOfNonAdjacent(vector<int> v,int index,vector<int>&dp)
{
    
    int prev=v[0];
    int prev2=0;
    for(int i=1;i<v.size();i++)
    {
        int take=v[i];
        if(i>1)take+=prev2;
    //    if(i==1) take+=0;
        int nontake=0+prev;
        int curr=max(take,nontake);
        prev2=prev;
        prev=curr;
    }
    return prev;
     
}

int main()
{
    vector<int> v={2,1,4,9};
    int n=4;
    int sum=0;
    // for memoization
    // vector<int> dp(n,-1);
    // cout<<MaxSumOfNonAdjacent(v,n-1,dp);

    // for tabulation
    vector<int> dp(n,0);
    cout<<MaxSumOfNonAdjacent(v,n-1,dp);
}