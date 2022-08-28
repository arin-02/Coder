#include<bits/stdc++.h>
using namespace std;


void nqueen(vector<vector<string>> &ans,int n,vector<string> &board,int col,vector<int> &leftrow,vector<int> &upperdiag,vector<int> &lowerdiag)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(leftrow[i]==0 &&lowerdiag[i+col]==0 && upperdiag[n-1+i-col]==0)
        {
            board[i][col]='Q';
            leftrow[i] =1;
            upperdiag[n-1+i-col] =1;
            lowerdiag[i+col] =1;
            nqueen(ans,n,board,col+1,leftrow,upperdiag,lowerdiag);
            board[i][col]='_';
            leftrow[i] =0;
            upperdiag[n-1+i-col] =0;
            lowerdiag[i+col] =0;
        }

    }
}
int main()
{
    vector<vector<string>> ans;
    int n=4;
    vector<string> board(n);
    vector<int> leftrow(n,0),upperdiag((2*n)-1,0),lowerdiag((2*n)-1,0);
    string s(n,'_');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }
    nqueen(ans,n,board,0,leftrow,upperdiag,lowerdiag);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<"  "<<endl;
        }
        cout<<endl;
    }
}