#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// o(n)

// frog jump kr skta hai 1 ya 2 aur energy kharch hogi abh minimum energy kharch ho aise jump btani 

// using recursion
// int frogjump(int index,vector<int> &heights)
// {
//     if(index==0) return 0;
//     if(index==1) return abs(heights[1]-heights[0]);

//     int left=frogjump(index-1,heights)+abs(heights[index]-heights[index-1]);
//     int right=INT_MAX;
//     // if(index>1)
//      right=frogjump(index-2,heights)+abs(heights[index]-heights[index-2]);
//     return min(left,right);
// }





// using memoization
// int frogjump(int index,vector<int> &heights,vector<int> &dp)
// {
//     if(index==0) return 0;
//     if(index==1) return abs(heights[1]-heights[0]);

//     if(dp[index]!=-1)return dp[index];
//     int left=frogjump(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
//     int right=INT_MAX;
//     // if(index>1)
//      right=frogjump(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
//     return dp[index]=min(left,right);
// }




// tabulation
void frogjump(vector<int> &heights,vector<int> &dp)
{
    dp[0]=0;
   dp[1]=abs(heights[1]-heights[0]);

    for(int i=2;i<=heights.size()-1;i++)
    {
        int first=dp[i-1]+abs(heights[i]-heights[i-1]);
        int second=INT_MAX;
        // if(i>1)
        second=dp[i-2]+abs(heights[i]-heights[i-2]);
        
        dp[i]=min(first,second);
    }
    cout<<dp[heights.size()-1]<<endl;
}
//  ya prev and prev2 leke bhi space optimize kr skte hai ...aur prev last mei print kro usmei answer hoga hmara...
int main()
{
    int n=6;
    vector<int> dp(n+1,-1);
    vector<int> heights={30,10,60,10,60,50};
    frogjump(heights,dp);
   
}