#include<bits/stdc++.h>
using namespace std;
// O(M^2 *M)=O(m^3)   ... TC

int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;

}
int main()
{
    vector<int> cuts={1,3,4,5};
    int n=cuts.size();//initial lengthofstick
    cuts.insert(cuts.begin(),0);//starting mei 0 dalna
    int lengthofstick=7; 
    cuts.push_back(lengthofstick);//end mei initial lengthofstick daali
    for(int i=0;i<cuts.size();i++)
    {
        cout<<cuts[i]<<" ";
    }
    cout<<endl;
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<solve(1,n,cuts,dp);

}