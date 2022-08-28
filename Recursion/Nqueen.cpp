#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>&board,int i,int col,int n)
{
    // check for 3 direction peeche vaale left upar diag peeche ka
    int row=i;
    int column=col;
    while(col>=0)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
        col--;
        
    }
    
     i=row;
     col=column;
    while(i>=0 && col>=0)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
        i--;
        col--;
        
    }
     i=row;
     col=column;
    
    while(i<n && col>=0)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
        i++;
        col--;
        
    }
    return true;

}
void nqueen(vector<vector<string>> &ans,int n,vector<string> &board,int col)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col,n))
        {
            board[i][col]='Q';
        nqueen(ans,n,board,col+1);
        board[i][col]='_';
        }

    }
}
int main()
{
    vector<vector<string>> ans;
    int n=4;
    vector<string> board(n);
    string s(n,'_');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }
    nqueen(ans,n,board,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<"  "<<endl;
        }
        cout<<endl;
    }
}