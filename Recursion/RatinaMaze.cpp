#include<iostream>
#include<vector>
#include<string>
using namespace std;


void solve(int i,int j,vector<vector<int> >&m,int n,vector<string>&ans,string move,vector<vector<int> >&visited)
{
    if(i==n-1&&j==n-1)
    {
        ans.push_back(move);
        return;
    }
    // downward
    
}
int main()
{
    vector<string> ans;
    int n=4;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> m={{1,0,0,0},
                            {1,1,0,1},
                            {1,1,0,0},
                            {0,1,1,1}};

    if(m[0][0]==1){solve(0,0,m,n,ans,"",vis);}
}