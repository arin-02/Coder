#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &m, int n, int x, int y) {
        if(x >= 0 && y >= 0 && x < n && y < n && m[x][y] == 1 ) {
            return true;
        }
        return false;
    }
bool solve(vector<vector<int>> &grid,int x1,int y1,int x2,int y2,int n,int m,int maxjump,int i,int j,vector<vector<int>> &visited)
{
    if(i<0 ||j<0 ||i>n-1||j>m-1 || maxjump<0) return false;

    if(i==x2-1&&j==y2-1 &&maxjump>=0) return true;

    if(grid[i][j]%grid[x2-1][y2-1] && maxjump>=0) return true;
    //down
        if(isSafe(grid, n, i+1, j)) {
             visited[i][j] = 1;
            
             return solve(grid, x1,y2,x2,y2,n,m,maxjump, i+1, j,visited);
            
             visited[i][j] == 0;
        }
        //left
        if(isSafe(grid, n, i, j-1)) {
            visited[i][j] = 1;
            maxjump=maxjump-1;
            return solve(grid, x1,y2,x2,y2,n,m,maxjump, i, j-1,visited);
            maxjump=maxjump+1;
           
             visited[i][j] == 0;
        }
        //right
        if(isSafe(grid, n, i, j+1)) {
            visited[i][j] = 1;
            
            maxjump=maxjump-1;
            return solve(grid, x1,y2,x2,y2,n,m,maxjump, i, j+1,visited);
            maxjump=maxjump+1;
           
             visited[i][j] == 0;
        }
        //up
        if(isSafe(grid, n, i-1, j)) {
            visited[i][j] = 1;
            
            maxjump=maxjump-1;
            return solve(grid, x1,y2,x2,y2,n,m,maxjump, i-1, j,visited);
            maxjump=maxjump+1;
            
             visited[i][j] == 0;
        }
        return true;
}
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> grid(n,vector<int> (m));
    vector<vector<int>> visited(n,vector<int> (m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int maxjump=4;
        if(solve(grid,x1,y1,x2,y2,n,m,maxjump,x1-1,x2-1,visited)){
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}