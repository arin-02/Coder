// assign weight 1 if no weight is specified
#include<bits/stdc++.h>
using namespace std;


void shortestDistance(vector<vector<int>> &adj,vector<int> &dist,int src)
{
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for(auto it:adj[x])
        {
             if(dist[x] + 1 < dist[it]){
		        dist[it]=dist[x]+1;
		        q.push(it);
		    }
        }

    }
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
}


int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V,vector<int>());
    // vector<int> vis(V,0);
   

    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
   
    vector<int> dist(V,INT_MAX);
    int src=0;
    dist[src]=0; //src node ko 0 
    shortestDistance(adj,dist,src);
    
   
   
    
}
// 9 11
// 0 1
// 1 3
// 0 3
// 1 2
// 3 4
// 4 5
// 5 6
// 2 6
// 6 7
// 7 8
// 6 8