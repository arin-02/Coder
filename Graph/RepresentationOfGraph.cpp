#include<bits/stdc++.h>
using namespace std;

int main()
{
    // check ki 1 based indexing hai ya 0 based ,,unse 1 jyada ka array bnana if 1 hua to
    // adjacent matrix 10^5 se km vaale n ke liye works krega kyuki n*n >10^8 ya 10^7
    // n=vertices,m=edges;
    int adj[n+1][n+1];

    // m tl loop chlana ,,, edges jitne... na hee vertices
    for(int i=0;i<m;i++) 
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }  


    // adjacentC list
    vector<int> ADJ(n+1);
    for(int i=0;i<m;i++) 
    {
        int u,v;
        cin>>u>>v;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }  
    // adjacentC list weighted graph
    vector<pair<int,int>> ADJ(n+1);
    for(int i=0;i<m;i++) 
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        ADJ[u].push_back({v,wt});
        ADJ[v].push_back({u,wt});
    }  
}