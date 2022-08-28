// agr count subset vaale mei arr[i]>=0 hue constraints to 
//  {0,0,1}
#include<bits/stdc++.h>
using namespace std;

int solver(vector<int> &arr,int target,int index,  vector<vector<int>> &dp)
{
  
    if(index==0)
     {
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target==arr[0]) return 1;
        return 0;
    }
    if(dp[index][target]!=-1) return dp[index][target];
    
    int notpick=solver(arr,target,index-1,dp);
    int pick=0;
    if(arr[index]<=target) {

        pick=solver(arr,target-arr[index],index-1,dp);
        }

    return dp[index][target]=pick+notpick;


}

int main()
{
    // number of subsets =2^n   
    // number of subsets * answer from count subsets 
    // ye total answer hai
    //   vector<int> arr={0,0,1};
      vector<int> arr={2 ,2 ,2 ,2 ,3, 4, 5};
    //   2 2 2 2 3 4 5

    int n=arr.size();
    // int target=1;
    int target=5;
    vector<vector<int>> dp(n,vector<int> (target+1,-1));
    int index=n-1;
    cout<<solver(arr, target,index,dp);  

}