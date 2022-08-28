#include<bits/stdc++.h>
using namespace std;

// O(n)
int solve(vector<int> &arr,int n)
{

    int mini=arr[0];
    int cost=0;
    int profit=0;
    for(int i=0;i<n;i++) 
    {
        cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);

    }
    return profit;

}
int main()
{
    
    vector<int>arr={7,1,5,3,6,4};
    // phele khareedna fir bechna
    int sz=arr.size(); 
    cout<<solve(arr,sz);

}