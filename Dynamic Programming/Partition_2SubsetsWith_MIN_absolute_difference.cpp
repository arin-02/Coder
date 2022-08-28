#include<iostream>
#include<vector>
using namespace std;



int main()
{
    vector<int> v={1,2,3,4};
    int target=9;
    int index=v.size();
// change start
    int totsum=0;
    for(int i=0;i<v.size();i++)
    {
        totsum+=v[i];
    }
    int k=totsum;

    vector<vector<bool>> dp(index,vector<bool> (k+1,0));
    // change end
    // Tabulation
   for(int i=0;i<index;i++)
   {
    dp[i][0]=true;
   }
   if(v[0]<=k) dp[0][v[0]]=true; //changed
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

//    change start again
    int mini=1e9;
    for(int i=0;i<totsum/2;i++){
        if(dp[index-1][i]==true)
        {
            mini=min(mini,abs((totsum-i)-i)); // checking difference between 2 subset
        }
    }
   cout<<mini<<endl;
}