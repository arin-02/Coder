// assign weight 1 if no weight is specified
#include<bits/stdc++.h>
using namespace std;


void shortestDistanceWeighted(vector<vector<pair<int,int>>> &adj,vector<int> &dist,int src)
{
    queue<pair<int,int>> q;
    q.push({dist[src],src});
    while(!q.empty())
    {
        int x = q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(auto it:adj[y])
        {
             if(dist[y] + it.second < dist[it.first]){
		        dist[it.first]=dist[y]+it.second;
		        q.push({dist[it.first],it.first});
		    }
        }

    }
    // 1 se likho dist ko 1 based indexing
    cout<<"distances are :-"<<endl;
    for(int i=1;i<=dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
}


int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> adj(V+1,vector<pair<int,int>>());
    // vector<int> vis(V,0);
   
    // 1 based indexing
    for(int i=1;i<=E;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }   
   
    vector<int> dist(V,1e9);
    int src=1;
    dist[src]=0; //src node ko 0 
    shortestDistanceWeighted(adj,dist,src);
    
   
   
    
}
// 5 6
// 1 2 2
// 1 4 1
// 2 5 5 
// 2 3 4
// 4 3 3 
// 3 5 1