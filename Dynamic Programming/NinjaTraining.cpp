#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// N*3 lena hai
int solve(vector<vector<int> >&v,int n,int taskdoneprevious,int day,vector<vector<int> >&dp)
{ 

    if(day==0)
    {
            int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=taskdoneprevious)
            {
                maxi=max(maxi,v[0][i]);
            }

        }
        return maxi;
    }
    if(dp[day][taskdoneprevious]!=-1)return dp[day][taskdoneprevious];

       int maxi=0;
    for(int i=0;i<3;i++)
    {
        
        if(i!=taskdoneprevious)
            {
                  int points=v[day][i] + solve(v,n,i,day-1,dp);

            maxi= max(maxi,points);
            }
        
    }
    return dp[day][taskdoneprevious]=maxi;

}
int main()
{
    vector<vector<int>> v={{10,50,2},
                    {11,100,4}};
        // for(int i=0; i<2; i++)
        // {
        //     vector<int> vv;
        //     for(int i=0;i<3;i++)
        //     {
        //         cin>>vv[i];
        //     }
        //     v.push_back(vv);
        // }         
    
    // int arr[4][3]={{2,1,3},
                        // {3,4,6},
                        // {10,1,6},
                        // {8,3,7}};

                    // ans =110 from dp 
                    // and greedy se 61



// memoisation and normal
    int n=2;//rows
    // vector<vector<int> >dp(n,vector<int>(4,-1));
    // int m=3;//taskdoneprevious
    // int ans=solve(v,n,3,n-1,dp);//task 0,1,2 hai 3 ka mtlbh all available tasks
    // cout<<ans<<endl;


// tabulation
// O(N*4*3) TC
// SC O(N*4)
    vector<vector<int> >dp(n,vector<int>(4,-1));

    dp[0][0]=max( v[0][1] , v[0][2]);
    dp[0][1]=max(v[0][0],v[0][2]);
    dp[0][2]=max(v[0][0],v[0][1]);
    dp[0][3]=max(v[0][1],max(v[0][1],v[0][2]));

    for(int day=1; day<n;day++)
    {
        for(int last=0; last<4;last++)
        {
            dp[day][last]=0;
            
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=v[day][task]+dp[day-1][task];
                    
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    cout<<dp[n-1][3]<<endl;

    
}