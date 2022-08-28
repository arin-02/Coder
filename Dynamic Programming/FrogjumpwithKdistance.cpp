#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// o(n)

// frog jump kr skta hai 1 ya 2 aur energy kharch hogi abh minimum energy kharch ho aise jump btani 

// using recursion
int frogjump(int index,vector<int> &heights,int k)
{
    if(index==0) return 0;
    int mmsteps=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        int jump;
        if(index-i>=0)
        {
         jump=frogjump(index-i,heights,k)+abs(heights[i]-heights[i-k]);

        }
        mmsteps=min(mmsteps,jump);
    }
    return mmsteps;
}


// check video

// VIDEO -4


//  ya prev and prev2 leke bhi space optimize kr skte hai ...aur prev last mei print kro usmei answer hoga hmara...
int main()
{
    int n=6;
    vector<int> dp(n+1,-1);
    vector<int> heights={30,10,60,10,60,50};
    cout<<(6,heights,4);
   
}