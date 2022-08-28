 #include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n,int index,int prev_index,vector<vector<int>> &dp)
{
    if(index==n)
    {
        return 0;
    }   
    
    if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];

    int nottake=0+solve(arr,n,index+1,prev_index,dp);
    int take=-1e9;
    if(arr[prev_index]<arr[index] || prev_index==-1)
    {
        take=1+solve(arr,n,index+1,index,dp);
    }
    return dp[index][prev_index+1]=max(take,nottake);
}
int main()
{
    vector<int> arr={10,9,2,5,3,7,101,18};
    // answer {2,3,7,101}   
    // answer {2,3,7,18}   
    // answer =length=4;
    int n=arr.size();
    int index=0;
    int prev_index=-1;
    // shifting of coordinate index.. kyuki prev_index=-1 hai ,, abh sbhko +1 krdo
    // prev_index ki jgah prev_index+1 krdo 
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    cout<<solve(arr,n,index,prev_index,dp);
}